#include "fdf.h"

int	key_control(int key_code, t_mlx *param)
{
	if (key_code == XK_Escape || key_code == 17)
	{
		mlx_destroy_image(param->mlx ,param->data->img);
		mlx_destroy_window(param->mlx ,param->mlx_win);
		if (param->file->points)
			free(param->file->points);
		if (param->file->fd > 2)
			close(param->file->fd);
		free(param->mlx);
		exit(0);
	}
	return (0);
}

void	error_control(int cntrl, t_mlx *param)
{
	if (cntrl == -1)
		perror(INVINP);
	if (cntrl == -2)
		perror(MALLERR);
	if (cntrl == -3)
		perror(FILEERR);
	if (cntrl == -4)
		perror(INVFORMAT);
	mlx_destroy_image(param->mlx ,param->data->img);
	mlx_destroy_window(param->mlx ,param->mlx_win);
	free(param->mlx);
	if (!param->file->points)
		free(param->file->points);
	if (param->file->fd > 2)
		close(param->file->fd);
	exit(1);
}

int	init_t_file(t_file *data)
{
	data->empty = 1;
	data->member = 0;
	data->n_member = 0;
	data->points = (t_point *)malloc(sizeof(t_point));
	if (!data->points)
		return(-2);
	data->row = 0;
	data->column = 0;
	data->x_rot = 40;
	data->y_rot = 15;
	data->z_rot = 0;
	return (0);
}
