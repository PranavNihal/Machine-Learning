#include <stdio.h>
#include "matrix.h"

int *matrix_scalar(const int *array, int rows, int cols, int scalar)
{
    if (array == NULL || rows <= 0 || cols <= 0)
    {
        return NULL;
    }

    int *scalartmatrix = create_matrix(rows, cols);
    if (scalartmatrix == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < (rows * cols); i++)
    {
        scalartmatrix[i] = array[i] * scalar;
    }
    return scalartmatrix;
}