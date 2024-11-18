/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:24:12 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/15 14:34:09 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "colors.h"
# include "mlx.h"
# include "get_next_line.h"
# include "libft.h"

# include <stdio.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include <fcntl.h>


# define WIDTH 1080
# define HEIGHT 720
# define SCALE 20
# define TITLE "fdf_map"


typedef	struct s_point{
	int x;
	int y;
	int z;

}			t_point;


typedef	struct s_file{
	t_point *points;
	int row;
	int member;
	int n_member;
	int empty;
	int column;
	float x_rot;
	float y_rot;
	float z_rot;


}			t_file;




typedef struct s_data {
    void    *img;
    int    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}               t_data;


void	get_values(int fd, t_file *data);
void	set_row(t_file *data,char **col);
t_point    *set_points(t_file *data,t_point *temp);
void    init_t_file(t_file *data);
void	draw_map(t_data *data,t_file *file);
void drawLine(t_data *data,t_point point1,t_point point2);
void put_pix(t_data *data,t_point point);
void	set_scale(t_file *file);


void	apply_rot_matrix_map(t_file *file);
static void	apply_rot_matrix_pt(t_point *point, float x, float y, float z);
static void	init_rot_matrix(float matrix[4][4], float x, float y, float z);


#endif