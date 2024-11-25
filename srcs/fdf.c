/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abturan <abturan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:13:20 by abturan           #+#    #+#             */
/*   Updated: 2024/11/25 19:31:01 by abturan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_control1(t_mlx *param)
{
	mlx_destroy_image(param->mlx, param->data->img);
	mlx_destroy_window(param->mlx, param->mlx_win);
	if (param->file->points)
		free(param->file->points);
	if (param->file->fd > 2)
		close(param->file->fd);
	free(param->mlx);
	exit(0);
}

void	init_program(t_mlx *mlx_st, char *argv)
{
	int	cntrl;

	mlx_st->mlx = mlx_init();
	mlx_st->mlx_win = mlx_new_window(mlx_st->mlx, WIDTH, HEIGHT, TITLE);
	mlx_st->data->img = mlx_new_image(mlx_st->mlx, WIDTH, HEIGHT);
	mlx_st->data->addr = (int *)mlx_get_data_addr(mlx_st->data->img,
			&mlx_st->data->bits_per_pixel,
			&mlx_st->data->line_length, &mlx_st->data->endian);
	cntrl = init_t_file(mlx_st->file);
	if (cntrl < 0)
		error_control(cntrl, mlx_st);
	cntrl = get_values(argv, mlx_st->file);
	if (cntrl < 0)
		error_control(cntrl, mlx_st);
		
	get_center(mlx_st->file);
	apply_rot_matrix_map(mlx_st->file);
	draw_map(mlx_st->data, mlx_st->file);
	mlx_put_image_to_window(mlx_st->mlx, mlx_st->mlx_win,
		mlx_st->data->img, 0, 0);
	mlx_key_hook(mlx_st->mlx_win, key_control, mlx_st);
	mlx_hook(mlx_st->mlx_win, 17, 0, key_control1, mlx_st);
	mlx_loop(mlx_st->mlx);
	close(mlx_st->file->fd);
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx_st;
	t_data	data;
	t_file	file;
	
	mlx_st.file = &file;
	mlx_st.data = &data;
	if (argc == 2)
		init_program(&mlx_st, argv[1]);
	perror("İnvalid input");
	return (-1);
}
