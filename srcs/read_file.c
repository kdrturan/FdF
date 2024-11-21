#include "fdf.h"


void    init_t_file(t_file *data)
{
    data->empty = 1;
    data->member = 0;
    data->n_member = 0;
    data->points = (t_point*)malloc(sizeof(t_point));
    data->row = 0;
    data->column = 0;
    data->x_rot = 40;
    data->y_rot = 15;
    data->z_rot = 0;
}
int index_hex(char ch)
{
    char *hex = "0123456789abcdef";
    char *hex_up = "0123456789ABCDEF";
    int i = -1;

    while (++i < 16)
        if (ch == hex[i] || ch == hex_up[i])
            return (i);
    return (-1);
}

int ft_puthex(char *str,t_file *data)
{
    int hex_val;
    int result;
    int i; 
    int len;

    len = 0;
    i = 2;
    result = 0;
    if (!str)
        return (CYAN);
    while (str[len])
        len++;
    while (str[i])
    {
        hex_val = index_hex(str[i]);

        result += hex_val * (int)pow(16, (len - i - 1));
        i++;
    }
    return (result);
}

void	set_row(t_file *data,char **col)
{
    t_point *temp;
    int i;

    i = -1;
    temp = NULL;
    if(data->column == 0)
        while (col[++i])
            data->column++;
    i = -1;
    while (col[++i])
    {
        if(data->member >= data->empty)
        {
            temp = (t_point *)malloc(data->empty * 2 * sizeof(t_point));
            if(!temp)
                error_control("Malloc error",data);
            data->points = ft_memmove(temp,data->points, sizeof(int) * 4 * data->member);
            data->empty *= 2;
        }
        data->points[data->member].x = i;
        data->points[data->member].y = data->row;
        data->points[data->member].z = ft_atoi(col[i]);
        data->points[data->member].color = ft_puthex(ft_strchr(col[i],','),data);
        data->member++;
    }
    data->row++;
}

int	get_values(t_file *data)
{
    char *values;


    data->fd =  open("test_maps/42.fdf", O_RDONLY);
	if (data->fd < 0)
        error_control("No such file",data);
    while (1)
    {
        values = get_next_line(data->fd);
        if (!values)
            break;
        set_row(data,ft_split(ft_strtrim(values," \n"),' '));
        free(values);
    }
    return(data->fd);
}
