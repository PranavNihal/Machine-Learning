#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void forward_pass(DenseLayer *layer, const float *X, float *out, int M)
{
    if (layer == NULL || X == NULL || out == NULL)
    {
        return;
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < layer->out_features; j++)
        {
            float sum = layer->biases[j];
            for (int k = 0; k < layer->in_features; k++)
            {
                sum += (X[i * layer->in_features + k]) * layer->weights[k * layer->out_features + j];
            }
            out[i * layer->out_features + j] = sum;
        }
    }
}