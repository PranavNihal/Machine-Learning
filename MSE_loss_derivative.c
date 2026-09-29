#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

float *mse_der(const float *predictions, const float *targets, int size)
{
    if (predictions == NULL || targets == NULL || size <= 0)
    {
        return NULL;
    }
    float *gradients = (float *)malloc(size * sizeof(float));
    if (gradients == NULL)
    {
        return NULL;
    }
    float factor = 2.0f / (float)size;
    for (int i = 0; i < size; i++)
    {
        gradients[i] = factor * (predictions[i] - targets[i]);
    }
    return gradients;
}