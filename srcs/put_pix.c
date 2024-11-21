#include "fdf.h"


void put_pix(t_data *data,t_point point,int color)
{
	if ((point.x + point.y * WIDTH) < WIDTH * HEIGHT && (point.x + point.y * WIDTH) > 0)
		data->addr[(point.x + point.y * WIDTH)] = color + point.z * 200;
}


void drawLine(t_data *data,t_point point1,t_point point2,int color) 
{
    int dx = abs(point2.x - point1.x);
    int dy = abs(point2.y - point1.y);

    int sx = (point1.x < point2.x) ? 1 : -1; 
    int sy = (point1.y < point2.y) ? 1 : -1; 

    int err = dx - dy;

    while (1) {

        put_pix(data,point1,color);

        if (point1.x == point2.x && point1.y == point2.y) 
			break;

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            point1.x += sx;
        }
        if (e2 < dx) {
            err += dx;
            point1.y += sy;
        }
    }
}

void	draw_map(t_data *data,t_file *file)
{
	int i;
	int j;

    j = 1;
	i = 0;
	while (i < file->member)
	{	

        if(file->column > j)
        {
            drawLine(data,file->points[i],file->points[i + 1],file->points->color);
            if(i / file->column != file->row - 1)
                drawLine(data,file->points[i],file->points[i + file->column],file->points->color);
            j++;
        }
        else
        {
            if(i / file->column != file->row - 1)
                drawLine(data,file->points[i],file->points[i + file->column],file->points->color);
            j = 1;
        }
        i++;
	}
}
