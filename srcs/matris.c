#include "fdf.h"

static	void	init_rot_matrix(float matrix[4][4], float x, float y, float z)
{
	matrix[0][0] = cosf(y) * cosf(z);
	matrix[1][0] = cosf(y) * sinf(z);
	matrix[2][0] = -sinf(y);
	matrix[3][0] = 0;
	matrix[0][1] = (sinf(x) * sinf(y) * cosf(z)) - (cosf(x) * sinf(z));
	matrix[1][1] = (sinf(x) * sinf(y) * sinf(z)) + (cosf(x) * cosf(z));
	matrix[2][1] = (sinf(x) * cosf(y));
	matrix[3][1] = 0;
	matrix[0][2] = (cosf(x) * sinf(y) * cosf(z)) + (sinf(x) * sinf(z));
	matrix[1][2] = (cosf(x) * sinf(y) * sinf(z)) - (sinf(x) * cosf(z));
	matrix[2][2] = cosf(x) * cosf(y);
	matrix[3][2] = 0;
	matrix[0][3] = 0;
	matrix[1][3] = 0;
	matrix[2][3] = 0;
	matrix[3][3] = 1;
}

static	void	apply_rot_matrix_pt(t_point *point, float x, float y, float z)
{
	float matrix[4][4];
	float x_new;
	float y_new;
	float z_new;

	x = x * (3.14 / 180);
	y = y * (3.14 / 180);
	z = z * (3.14 / 180);
	init_rot_matrix(matrix, x, y, z);
	x_new = matrix[0][0] * point->x + matrix[0][1] * point->y + matrix[0][2] * point->z + matrix[0][3] * 1;
	y_new = matrix[1][0] * point->x + matrix[1][1] * point->y + matrix[1][2] * point->z + matrix[1][3] * 1;
	point->x = x_new;
	point->y = y_new;
}

void	apply_rot_matrix_map(t_file *file)
{
	int	i;

	i = -1;
	while (++i < file->member)
		apply_rot_matrix_pt(&(file->points[i]), file->x_rot, file->y_rot, file->z_rot);
}