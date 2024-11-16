#include "fdf.h"


void put_pix(t_data *data,int color,int cordinate)
{
	data->addr[cordinate] = color;
}

void put_line(t_file *file, t_data *data)
{
	int	i = 0;
	int	j = 0;
	int k = 0;
	int cordinate_y = 0;
	int cordinate_x = 0;
	while (i < file->row)
	{
		printf("%d\n",cordinate_x);
		j = 0;
		cordinate_x = (SCALE * WIDTH * i);
		while (j < file->column)
		{
			k = 0;
			cordinate_y = cordinate_x ; 
			while (k < SCALE)
			{
				put_pix(data, 50 + (file->values[i][j] * 50) ,cordinate_x);
				put_pix(data, 50 + (file->values[i][j] * 50) ,cordinate_y + (k * WIDTH));
				cordinate_x++;
				k++;
			}
			j++;
		}
		cordinate_x += WIDTH;
		i++;
	}
}