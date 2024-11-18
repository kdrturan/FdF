#include "fdf.h"


void    init_t_file(t_file *data)
{
    data->empty = 1;
    data->member = 0;
    data->n_member = 0;
    data->points = (t_point*)malloc(sizeof(t_point));
    data->row = 0;
}

void	set_row(t_file *data,char **col)
{
    t_point *temp;
    int i;

    i = -1;
    temp = NULL;

    while (col[++i])
    {
        if(data->member >= data->empty)
        {
            temp = (t_point *)malloc(data->empty * 2 * sizeof(t_point));
            data->points = ft_memmove(temp,data->points, sizeof(int) * 3 * data->member);
            data->empty *= 2;
        }
        data->points[data->member].x = i;
        data->points[data->member].y = data->row;
        data->points[data->member].z = ft_atoi(col[i]);
        data->member++;
    }
    data->row++;
}

void	get_values(int fd, t_file *data)
{
    char *values;
    char **col;

    while (1)
    {
        values = get_next_line(fd);
        if (!values)
            break;
        col = ft_split(ft_strtrim(values," \n"),' ');
        set_row(data,col);
        free(values);
    }

}
