#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

float MSE_Loss(const float *predictions, const float *targets, int size)
{
    if (predictions == NULL || targets == NULL || size <= 0)
    {
        return -1.0f;
    }
    float sum = 0.0f;
    /*We use this loss as it makes small errors
    more obvious and elmiminates negatives as it is squared*/
    for (int i = 0; i < size; i++)
    {
        float difference = targets[i] - predictions[i];
        sum += (difference * difference);
    }
    float MSE = sum / (float)size;
    return MSE;
}