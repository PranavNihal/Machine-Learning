#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
void sgd(float *params, const float *grads, float lr, int size, int M)
{
    if (params == NULL || grads == NULL || lr <= 0.0f || size <= 0 || M <= 0)
    {
        return;
    }
    float eff_lr = lr / (float)M;
    for (int i = 0; i < size; i++)
    {
        params[i] -= eff_lr * grads[i];
    }
}
void sgd_update_layer(DenseLayer *layer, float lr, int M)
{
    if (layer == NULL)
    {
        return;
    }
    int total_weights = layer->in_features * layer->out_features;
    int total_biases = layer->out_features;

    sgd(layer->weights, layer->dW, lr, total_weights, M);
    sgd(layer->biases, layer->dB, lr, total_biases, M);
}