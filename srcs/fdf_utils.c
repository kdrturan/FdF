#include "fdf.h"

int key_control(int key_code,void *param)
{
	if(key_code == XK_Escape)
		exit(0);
}

void	error_control(char *error,t_file *data)
{
	perror(error);
	close(data->fd);
	exit(-1);
}

void    init_t_file(t_file *data)
{
    data->empty = 1;
    data->member = 0;
    data->n_member = 0;
    data->points = (t_point*)malloc(sizeof(t_point));
    if (!data->points)
        error_control("Malloc error",data);    
    data->row = 0;
    data->column = 0;
    data->x_rot = 40;
    data->y_rot = 15;
    data->z_rot = 0;
}

void	set_scale(t_file *file)
{
	int i;

	i = 0;
	while (i < file->member)
	{
		file->points[i].x *= SCALE;
		file->points[i].y *= SCALE;
		file->points[i].z *= 1;
		i++;
	}
}