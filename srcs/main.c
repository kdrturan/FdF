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





int main()
{
	int fd;
	void    *mlx;
    void    *mlx_win;
    t_data  img;
	t_file file;

	int i = 0;
	int j = 0;
	init_t_file(&file);
	fd = get_values(&file);
	mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Merhaba Dünya!");
    img.img = mlx_new_image(mlx,  WIDTH, HEIGHT);
    img.addr = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	set_scale(&file);
	apply_rot_matrix_map(&file);
	draw_map(&img,&file);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0); 
	mlx_key_hook(mlx_win,key_control,&img);
    mlx_loop(mlx);

	close(fd);
	return (0);
}
