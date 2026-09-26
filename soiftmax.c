#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include <math.h>

float *softmax(const int *array, int rows, int cols)
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
    for (int i = 0; i < rows; i++)
    {
        float sum = 0.0f;
        for (int j = 0; j < cols; j++)
        {
            int index = i * cols + j;
            sum += expf((float)array[index]);
        }
        for (int j = 0; j < cols; j++)
        {
            int index = i * cols + j;
            applied[index] = expf((float)array[index]) / sum;
        }
    }
    return applied;
}