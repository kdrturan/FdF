#include "fdf.h"



void    operation_x(t_file *file,char c)
{
    int i;

    i = -1;
    if (c == '-')
        while (++i < file->member)
            file->points[i].x += 5;
    else if (c == '+')
        while (++i < file->member)
            file->points[i].x -= 5;  

}


void	operation_y(t_file *file,char c)
{
    int i;

    i = -1;
    if (c == '-')
        while (++i < file->member)
            file->points[i].y += 5;
    else if (c == '+')
        while (++i < file->member)
            file->points[i].y -= 5;
}


void	operation_z(t_file *file,char c)
{
    int i;

    i = -1;
    if (c == '-')
        while (++i < file->member)
            file->points[i].z += 5;
    else if (c == '+')
        while (++i < file->member)
            file->points[i].z -= 5;  
}


void put_pix_index(t_data *data,int point,int color)
{
		data->addr[point] = color;

}


void    draw_black(t_file *file,t_data *data)
{
    int i;

    i = 0;
	while (i < WIDTH * HEIGHT)
    {
        put_pix_index(data,i,0);
        i++;
        printf("%d\n",i);
    }
    
    
}


void	key_hook(int key_code,t_file *file,t_data *data)
{
	if(key_code ==  XK_q)
		printf("s\n");
    if(key_code ==  XK_w)
		operation_x(file,'+');
    if(key_code ==  XK_a)
		operation_y(file,'-');
    if(key_code ==  XK_s)
		operation_y(file,'+');
    if(key_code ==  XK_z)
		operation_z(file,'-');
    if(key_code ==  XK_x)
		operation_z(file,'+');
    if(key_code ==  XK_e)
		printf("%d\n",key_code);
    if(key_code ==  XK_r)
		printf("%d\n",key_code);
    draw_black(file,data);
}

