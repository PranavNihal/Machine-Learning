#include <stdio.h>
#include "matrix.h"

int dense_layer_backward(DenseLayer *layer, const float *X, const float *d_out, float *dX, int M)
{
    if (layer == NULL)
    {
        return -1;
    }
    return backward(
        X,
        layer->weights,
        d_out,
        layer->dW,
        layer->dB,
        dX,
        M,
        layer->in_features,
        layer->out_features);
}