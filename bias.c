#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
int *matrix_bias(const int *M, int rows, int cols, const int *B)
{
    if (rows <= 0 || cols <= 0 || M == NULL || B == NULL)
    {
        return NULL;
    }
    int *bias = create_matrix(rows, cols);
    if (bias == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int index = i * cols + j;
            bias[index] = M[index] + B[j];
        }
    }
    return bias;
}