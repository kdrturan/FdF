#include "fdf.h"

int key_control(int key_code,void *param)
{
	if(key_code == XK_Escape)
		exit(0);
}


void	error_control(char *error,t_file *data)
{
	perror(error);
	close(data->fd);
	exit(-1);
}