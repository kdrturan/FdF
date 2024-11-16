#include "fdf.h"


void put_pix_file(t_file *file, t_data *data)
{
	int i = 0;
	int j = 0;
	int	*temp;
	while (i < file->row)
	{
		j = 0;
		while (j < file->column)
		{
			temp = *(data->addr) + (i * WIDTH) + j;
			temp = file->values[i][j];
			j++;
		}
		i++;
	}
	
}