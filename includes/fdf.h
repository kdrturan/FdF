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
# define SCALE 2
# define TITLE "fdf_map"



typedef	struct s_file{
	int column;
	int row;
	int **values;

}			t_file;


typedef struct s_point{
	int x1;
	int x2;
	int y1;
	int y2;
	int color;
} 		t_point;


typedef struct s_data {
    void    *img;
    int    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}               t_data;


void	get_values(int fd,t_file *file);
int	get_col(int fd,t_file *file);
void put_pix(t_data *data,int color,int cordinate);
void put_line(t_file *file, t_data *data);




#endif