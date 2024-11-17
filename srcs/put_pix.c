#include "fdf.h"


void put_pix(t_data *data,int color,int cordinate)
{

	if (cordinate < WIDTH * HEIGHT)
		data->addr[cordinate] = color;
}





// void put_line(t_file *file, t_data *data)
// {
// 	int	i = 0;
// 	int	j = 0;
// 	int k = 0;
// 	int cordinate_y = 0;
// 	int cordinate_x = 0;
// 	while (i < file->row)
// 	{
// 		printf("%d\n",cordinate_x);
// 		j = 0;
// 		cordinate_x = (SCALE * WIDTH * i);
// 		while (j < file->column)
// 		{
// 			k = 0;
// 			cordinate_y = cordinate_x ; 
// 			while (k < SCALE)
// 			{
// 				put_pix(data, 50 + (file->values[i][j] * 50) ,cordinate_x);
// 				put_pix(data, 50 + (file->values[i][j] * 50) ,cordinate_y + (k * WIDTH));
// 				cordinate_x++;
// 				k++;
// 			}
// 			j++;
// 		}
// 		cordinate_x += WIDTH;
// 		i++;
// 	}
// }




// void draw_line(int *x1, int x2, int *y1, int y2,t_data *data) {
//     int dx = abs(x2 - *x1);
//     int dy = abs(y2 - *y1);
//     int sx = (*x1 < x2) ? 1 : -1;
//     int sy = (*y1 < y2) ? 1 : -1;
//     int err = dx - dy;

//     printf("Çizgi noktaları:\n");
//     while (1) {
// 		put_pix(data,200,x1 + );

//         if (*x1 == x2 && *y1 == y2) break;

//         int e2 = 2 * err;

//         if (e2 > -dy) {
//             err -= dy;
//             *x1 += sx;
//         }

//         if (e2 < dx) {
//             err += dx;
//             *y1 += sy;
//         }
//     }
// }




// void draw_map(t_file *file, t_data *data,t_cordinate *cordinate)
// {
// 	int i = 0;
// 	int j = 0;
// 	while (i < file->row)
// 	{
// 		j = 0;
// 		while (j < file->column)
// 		{
// 			draw_line(cordinate->cordinate_x,cordinate->cordinate_x + SCALE,cordinate->cordinate_y,cordinate->cordinate_y,data);
// 			j++;
// 		}
// 		i++;
// 	}
	

// }








