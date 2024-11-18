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
	void    *mlx;
    void    *mlx_win;
    t_data  img;
	t_file file;

	int fd = open("test_maps/elem2.fdf", O_RDONLY);
	if (fd < 0)
	{
		perror("Dosya açılmadı");
		return (1);
	}
	int i = 0;
	int j = 0;

	init_t_file(&file);
	get_values(fd,&file);
	printf("%d\n",file.points[43].z);
	mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1080, 720, "Merhaba Dünya!");
    img.img = mlx_new_image(mlx,  1080, 720);
    img.addr = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	set_scale(&file);
	apply_rot_matrix_map(&file);
	draw_map(&img,&file);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);  
    mlx_loop(mlx);

}

















// void my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
//     char    *dst;
	
//     dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//     *(unsigned int*)dst = color;
// }

// void DrawCurvedLine(t_data *img, t_point point) {

// 	int x = point.x1;
// 	int y = point.y1;
//     while (x <= point.x2) {
//         // Sin ve cos ile renk değişimlerini hesapla (örnek olarak)
// 		point.color += 100;
//         my_mlx_pixel_put(img, x, y, point.color);

//         x = x + 1;
// 		y = y + 1;
//     }
// }

// void draw_x(t_data *img, t_point point)
// {
// 	int i = 0;
// 	int x = point.x1;
// 	int x2 = point.x2;
// 	int y1 = point.y1;
// 	while (point.y1 <= point.y2) 
// 	{
// 		i = 0;
// 		point.color += 60;
// 		while(i <= x2 - x)
//         	my_mlx_pixel_put(img, x + i++, y1, point.color);
//         point.y1 += 1;
// 		y1 += 20;
//     }
// }

// void draw_y(t_data *img, t_point point)
// {
// 	int i = 0;
// 	int x = point.x1;
// 	while (point.x1 <= point.x2) 
// 	{
// 		i = 0;
// 		point.color += 60;
// 		while (i <= point.y2 - point.y1)
//         	my_mlx_pixel_put(img, x , point.y1 + i++, point.color);
//         point.x1 += 1;
// 		x += 20;
//     }
// }

// int main(void)
// {
//     void    *mlx;
//     void    *mlx_win;
//     t_data  img;
// 	t_point point;

// 	point.x1 = 10;
// 	point.x2 = 100;
// 	point.y1 = 10;
// 	point.y2 = 20;
// 	point.color = 600;
//     mlx = mlx_init();
//     mlx_win = mlx_new_window(mlx, 1080, 720, "Merhaba Dünya!");
//     img.img = mlx_new_image(mlx,  1080, 720);
//     img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	draw_x(&img,point);
// 	draw_y(&img,point);
//       // Kırmızı piksel yazılır.
//     mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);  // Görüntü pencereye gönderilir.
//     mlx_loop(mlx);
// }

