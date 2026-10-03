#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include <math.h>

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

void mse_der(const float *predictions, const float *targets, float *d_out, int size)
{
    if (predictions == NULL || targets == NULL || d_out == NULL || size <= 0)
    {
        return;
    }
    float factor = 2.0f / (float)size;
    for (int i = 0; i < size; i++)
    {
        d_out[i] = factor * (predictions[i] - targets[i]);
    }
}

float cross_entropy_loss(const float *y_pred, const float *y_true, float *d_out, int num_samples, int num_classes)
{
    if (y_pred == NULL || y_true == NULL || num_classes <= 0 || num_samples <= 0)
    {
        return 0.0f;
    }
    float tot_loss = 0.0f;
    for (int i = 0; i < num_samples; i++)
    {
        for (int j = 0; j < num_classes; j++)
        {
            int idx = i * num_classes + j;
            tot_loss -= y_true[idx] * logf(y_pred[idx] + 1e-7);
            d_out[idx] = y_pred[idx] - y_true[idx];
            if (d_out != NULL)
            {
                d_out[idx] = y_pred[idx] - y_true[idx];
            }
        }
    }
    return tot_loss / (float)num_samples;
}