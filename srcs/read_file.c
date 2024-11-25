/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abturan <abturan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:48:51 by abturan           #+#    #+#             */
/*   Updated: 2024/11/25 16:48:51 by abturan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	freesplit(char **col, int wc)
{
	while (col[wc])
	{
		free(col[wc]);
		wc++;
	}
	free(col);
}

static	t_point	*get_col(t_file *data, char **col)
{
	t_point	*temp;
	int		i;

	i = -1;
	temp = NULL;
	while (col[++i])
		data->column++;
	return (temp);
}

static	int	set_row(t_file *data, char **col)
{
	t_point	*temp;
	int		i;

	i = -1;
	if (data->column == 0)
		temp = get_col(data, col);
	while (col[++i])
	{
		if (data->member >= data->empty)
			if (point_move(data) < 0)
				return (-2);
		data->points[data->member].x = i * SCALE;
		data->points[data->member].y = data->row * SCALE;
		data->points[data->member].z = ft_atoi(col[i]) / Z_SCALE;
		data->points[data->member].color.clr = ft_puthex(
				ft_strchr(col[i], ','), data);
		if (ft_puthex(ft_strchr(col[i], ','), data) < 0)
			return (freesplit(col, i), -1);
		data->member++;
		free(col[i]);
	}
	data->row++;
	return (free(col), 0);
}

int	get_values(char *argv, t_file *data)
{
	t_get_val	get_val;
	int			i;

	i = 0;
	printf("%s\n",argv);
	get_val.file_f = ft_strrchr(argv, '.');
	while (i < 4)
		if (!get_val.file_f && get_val.file_f[i] != FORMAT[i])
			return (-4);
	data->fd = open("/home/kdrturan/fdf_42/test_maps/42.fdf", O_RDONLY);
	if (data->fd < 0)
		return (-3);
	while (1)
	{
		get_val.values = get_next_line(data->fd);
		if (!get_val.values)
			break ;
		get_val.valtrim = ft_strtrim(get_val.values, " \n");
		get_val.valsplit = ft_split(get_val.valtrim, ' ');
		get_val.cntrl = set_row(data, get_val.valsplit);
		free(get_val.valtrim);
		free(get_val.values);
		if (get_val.cntrl < 0)
			return (get_val.cntrl);
	}
	return (0);
}
