#include "fdf.h"

void	set_scale(t_file *file)
{
	int i;

	i = 0;
	while (i < file->member)
	{
		file->points[i].x *= SCALE;
		file->points[i].y *= SCALE;
		file->points[i].z *= 1;
		i++;
	}
}