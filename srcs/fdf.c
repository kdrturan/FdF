/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:26:35 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/15 14:33:53 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_file	file;

	//if (argc == 2)
	//{
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, TITLE);
		img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
		img.addr = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		init_t_file(&file);
		get_values(argv, &file);
		apply_rot_matrix_map(&file);
		draw_map(&img, &file);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		mlx_key_hook(mlx_win, key_control, &file);
		mlx_hook(mlx_win, 17, 1L << 17, key_control, &file);
		mlx_loop(mlx);
		close(file.fd);
		return (0);
	//}
	//error_control("İnvalid input", &file);
}
