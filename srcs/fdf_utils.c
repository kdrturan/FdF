#include "fdf.h"

int	key_control(int key_code, t_file *param)
{
	if (key_code == XK_Escape || key_code == 17)
	{
		free(param->points);
		mlx_destroy_image();
		exit(0);
	}
	return (0);
}

void	error_control(char *error, t_file *data)
{
	free(data->points);
	perror(error);
	close(data->fd);
	exit(-1);
}

void	init_t_file(t_file *data)
{
	data->empty = 1;
	data->member = 0;
	data->n_member = 0;
	data->points = (t_point *)malloc(sizeof(t_point));
	if (!data->points)
		error_control("Malloc error", data);
	data->row = 0;
	data->column = 0;
	data->x_rot = 40;
	data->y_rot = 15;
	data->z_rot = 0;
}
