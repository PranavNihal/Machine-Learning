#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

float *softmax_der(const int *array, int rows, int cols)
{
    if (array == NULL || cols <= 0 || rows <= 0)
    {
        return NULL;
    }
    
    float *result = (float *)malloc(rows * cols * sizeof(float));
}