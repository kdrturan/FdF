#include "fdf.h"

void    put_pix(t_data *data, t_point point, t_color color)
{
    if ((point.x + point.y * WIDTH) < WIDTH * HEIGHT && (point.x + point.y * WIDTH) > 0)
        data->addr[(point.x + point.y * WIDTH)] = color.clr;
}



void drawpix(t_line	line,t_data *data, t_point point1, t_point point2)
{

	while (1)
	{
		t_color current_color;
		current_color.r = fmin(fmax((int)line.r, 0), 255);
		current_color.g = fmin(fmax((int)line.g, 0), 255);
		current_color.b = fmin(fmax((int)line.b, 0), 255);

		put_pix(data, point1, current_color);
		if (point1.x == point2.x && point1.y == point2.y)
			break;
		int e2 = 2 * line.err;
		if (e2 > -(line.dy))
		{
			line.err -= line.dy;
			point1.x += line.sx;
		}
		if (e2 < line.dx)
		{
			line.err += line.dx;
			point1.y += line.sy;
		}
		line.r += line.r_step;
		line.g += line.g_step;
		line.b += line.b_step;
	}
}




void	drawLine(t_data *data, t_point point1, t_point point2)
{
	t_line	line;

	line.dx = abs(point2.x - point1.x);
	line.dy = abs(point2.y - point1.y);
	line.sx = (point1.x < point2.x) ? 1 : -1;
	line.sy = (point1.y < point2.y) ? 1 : -1;
	line.err = line.dx - line.dy;
	line.hip = sqrt(line.dx * line.dx + line.dy * line.dy);
	line.r_step = (float)(point2.color.r - point1.color.r) / line.hip;
	line.g_step = (float)(point2.color.g - point1.color.g) / line.hip;
	line.b_step = (float)(point2.color.b - point1.color.b) / line.hip;
	line.r = point1.color.r;
	line.g = point1.color.g;
	line.b = point1.color.b;
	drawpix(line,data,point1,point2);
}

void    draw_map(t_data *data, t_file *file)
{
    int i;
    int j;

    j = 1;
    i = 0;
    while (i < file->member)
    {

        if (file->column > j)
        {
            drawLine(data, file->points[i], file->points[i + 1]);
            if (i / file->column != file->row - 1)
                drawLine(data, file->points[i], file->points[i + file->column]);
            j++;
        }
        else
        {
            if (i / file->column != file->row - 1)
                drawLine(data, file->points[i], file->points[i + file->column]);
            j = 1;
        }
        i++;
    }
}
