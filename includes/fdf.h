/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abturan <abturan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:33:16 by abturan           #+#    #+#             */
/*   Updated: 2024/11/25 18:06:11 by abturan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "colors.h"
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH		1080
# define HEIGHT		720
# define SCALE		55
# define Z_SCALE	0.6
# define DELTA		10
# define TITLE		"Hello Fdf!"
# define FORMAT		".fdf"
# define INVINP		"Invalid Input"
# define INVFORMAT	"Invalid Format"
# define MALLERR	"Malloc Error"
# define FILEERR	"No Such File or Directory"

typedef struct s_get_val
{
	char	*values;
	char	*valtrim;
	char	**valsplit;
	int		cntrl;
	char	*file_f;
}	t_get_val;

typedef struct s_line
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	float	hip;
	float	r_step;
	float	g_step;
	float	b_step;
	float	r;
	float	g;
	float	b;
}	t_line;

typedef union u_color
{
	struct
	{
		__uint8_t	b;
		__uint8_t	g;
		__uint8_t	r;
		__uint8_t	a;
	};
	__uint32_t	clr;
}	t_color;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	t_color	color;
}	t_point;

typedef struct s_file
{
	t_point	*points;
	int		row;
	int		member;
	int		n_member;
	int		empty;
	int		column;
	float	x_rot;
	float	y_rot;
	float	z_rot;
	int		fd;
}	t_file;

typedef struct s_data
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	t_data	*data;
	t_file	*file;
}	t_mlx;
int		get_values(char *argv, t_file *data);
t_point	*set_points(t_file *data, t_point *temp);
int		init_t_file(t_file *data);
void	draw_map(t_data *data, t_file *file);
void	draw_line(t_data *data, t_point point1, t_point point2);
void	put_pix(t_data *data, t_point point, t_color color);
int		key_control(int key_code, t_mlx *param);
void	error_control(int cntrl, t_mlx *param);
void	apply_rot_matrix_map(t_file *file);
int		index_hex(char ch);
int		ft_puthex(char *str, t_file *data);


#endif