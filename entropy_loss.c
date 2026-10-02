#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

float cross_entropy_loss(const float *y_pred, const float *y_true, float *d_out, int num_samples, int num_classes)
{
    if (y_pred == NULL || y_true == NULL)
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
        }
    }
    return tot_loss / (float)num_samples;
}