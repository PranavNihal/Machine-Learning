#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int *RELU_der(const int *array, int rows, int cols)
{
    if (array == NULL || cols <= 0 || rows <= 0)
    {
        return NULL;
    }
    int size = cols * rows;
    int *result = (int *)malloc(size * sizeof(int));
    if (result == NULL)
    {
        return NULL;
    }
    for (int i = 0; i <= size; i++)
    {
        if (array[i] > 0)
        {
            result[i] = 1;
        }
        else
        {
            result[i] = 0;
        }
    }
    return result;
}
