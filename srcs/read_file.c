#include "fdf.h"



int	**set_row(t_file *file)
{
    int i;
    int **temp;

    i = 0;
    temp = (int **)malloc(sizeof(int *) * (file->row + 1));
    while (i < file->row)
    {
        temp[i] = file->values[i];
        i++;
    }
    free(file->values); 
    return (temp);
}


int	get_col(int fd, t_file *file)
{
    int		i;
    char	*gnl;
    char	*col;
    char	**temp;

    i = 0;
    gnl = get_next_line(fd);
    if (gnl == NULL)
        return (0);
    col = ft_strtrim(gnl, " \n");
    free(gnl);
    temp = ft_split(col, ' ');
    free(col);
    if (file->column == 0)
        while (temp[i++])
            file->column++;
    file->values = set_row(file);
    file->values[file->row] = (int *)malloc(sizeof(int) * file->column);
    i = -1;
    while (temp[++i])
        file->values[file->row][i] = ft_atoi(temp[i]);
    
    i = 0;
    while (temp[i])
        free(temp[i++]);
    free(temp);
    return (1);
}

void	get_values(int fd, t_file *file)
{
    file->row = 0;
    file->column = 0;
    file->values = NULL; 
    while (1)
    {
        if (!get_col(fd, file))
            break;
        file->row++;
    }
}
