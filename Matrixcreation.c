#include <stdio.h>
#include <stdlib.h>
int *create_matrix(int rows, int cols)

{
    if (rows <= 0 || cols <= 0)
    {
        return NULL;
    }
    int *matrix = calloc((cols * rows), sizeof(int));
    if (matrix == NULL)
    {
        return NULL;
    }
    return matrix;
}

void free_matrix(int *matrix)
{
    if (matrix == NULL)
    {
        return;
    }
    else
    {
        free(matrix);
    }
    return;
}
