#include <stdio.h>
#include "matrix.h"
#include <stdlib.h>
// for e
#include <math.h>
float *sigmoid(const int *array, int rows, int cols)
{
    if (rows <= 0 || cols <= 0 || array == NULL)
    {
        return NULL;
    }
    float *applied = (float *)malloc(rows * cols * sizeof(float));
    if (applied == NULL)
    {
        return NULL;
    }
    int size = rows * cols;
    for (int i = 0; i < size; i++)
    {
        // sigmoid function
        applied[i] = 1.0f / (1.0f + expf(-array[i]));
    }
    return applied;
}