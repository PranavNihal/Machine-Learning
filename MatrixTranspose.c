#include <stdio.h>
#include "matrix.h"

int *matrix_transpose(const int *Array, int rows, int cols)
{
    if (Array == NULL || rows <= 0 || cols <= 0)
    {
        return NULL;
    }
    int *transpose = create_matrix(cols, rows);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j * rows + i] = Array[i * cols + j];
        }
    }
    return transpose;
}