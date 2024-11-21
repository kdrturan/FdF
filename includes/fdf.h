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
# define SCALE 40
# define Z_SCALE 0.2
# define DELTA	10
# define TITLE "Hello Fdf!"

typedef struct s_line
{
	int dx;
    int dy;
    int sx; 
    int sy; 
    int err;
	int e2;
}	t_line;



typedef	struct s_point{
	int x;
	int y;
	int z;
	int color;
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
	int fd;
}			t_file;


typedef struct s_data {
    void    *img;
    int    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}               t_data;



int	get_values(char **argv,t_file *data);
void	set_row(t_file *data,char **col);
t_point    *set_points(t_file *data,t_point *temp);
void    init_t_file(t_file *data);
void	draw_map(t_data *data,t_file *file);
void drawLine(t_data *data,t_point point1,t_point point2,int color);
void put_pix(t_data *data,t_point point,int color);
void	set_scale(t_file *file);
int key_control(int key_code,void *param);
void	error_control(char *error,t_file *data);

void	apply_rot_matrix_map(t_file *file);
static void	apply_rot_matrix_pt(t_point *point, float x, float y, float z);
static void	init_rot_matrix(float matrix[4][4], float x, float y, float z);

#endif