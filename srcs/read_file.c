#include "fdf.h"

static	int	index_hex(char ch)
{
	char	*hex = "0123456789abcdef";
	char	*hex_up = "0123456789ABCDEF";
	int	i;

	i = -1;
	while (++i < 16)
		if (ch == hex[i] || ch == hex_up[i])
			return (i);
	return (-1);
}

static	int	ft_puthex(char *str, t_file *data)
{
	int	hex_val;
	int	result;
	int	i;
	int	len;

	len = 0;
	i = 0;
	result = 0;
	if (!str)
		return (YELLOW);
	if (str[1] != '0' && (str[2] != 'x' || str[2] != 'X'))
		return (-1);
	str += 3;
	while (str[len])
		len++;
	while (str[i])
	{
		hex_val = index_hex(str[i]);
		if (hex_val == -1)
		 	return (-1);
		result += hex_val * (int)pow(16, (len - i - 1));
		i++;
	}
	return (result);
}

static	int	point_move(t_file *file)
{
	t_point	*temp;
	t_point	*temp2;

	temp = NULL;
	temp = (t_point *)malloc(file->empty * 2 * sizeof(t_point));
	if (!temp)
		return (-2);
	temp2 = ft_memmove(temp, file->points, sizeof(t_point) * file->member);
	free(file->points);
	file->points = temp2;
	file->empty *= 2;
	return (0);
}

void	freesplit(char **col,int wc)
{
	while (col[wc])
	{
		free(col[wc]);
		wc++;
	}
	free(col);
}

static	int	set_row(t_file *data, char **col)
{
	t_point	*temp;
	int	i;

	i = -1;
	temp = NULL;
	if (data->column == 0)
		while (col[++i])
			data->column++;
	i = -1;
	while (col[++i])
	{
		if (data->member >= data->empty)
			if (point_move(data) < 0)
				return(-2);
		data->points[data->member].x = i * SCALE;
		data->points[data->member].y = data->row * SCALE;
		data->points[data->member].z = ft_atoi(col[i]) / Z_SCALE;
		data->points[data->member].color.clr = ft_puthex(ft_strchr(col[i], ','), data);
		if(ft_puthex(ft_strchr(col[i], ','), data) < 0)
		{
			freesplit(col,i);
			return(-1);
		}
		data->member++;
		free(col[i]);
	}
	free(col);
	data->row++;
	return(0);
}

int	get_values(char *argv, t_file *data)
{
	char	*values;
	char	*valtrim;
	char	**valsplit;
	int	cntrl;
	char *file_f;
	int i;

	i = 0;
	// file_f = ft_strrchr(argv[1],'.');
	// while (i < 4)
	// 	if(!file_f && file_f[i] != FORMAT[i] )
	// 		return (-4);	
	data->fd = open("/home/kdrturan/fdf_42/test_maps/42.fdf", O_RDONLY);
	if (data->fd < 0)
		return (-3);
	while (1)
	{
		values = get_next_line(data->fd);
		if (!values)
			break;
		valtrim = ft_strtrim(values, " \n");
		valsplit = ft_split(valtrim, ' ');
		cntrl = set_row(data, valsplit);
		free(valtrim);
		free(values);
		if (cntrl < 0)
			return(cntrl);
	}
	return (0);
}
