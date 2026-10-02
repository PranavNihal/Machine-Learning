#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

DenseLayer *dense_layer_create(int in_features, int out_features)
{
    if (in_features <= 0 || out_features <= 0)
    {
        return 0;
    }
    DenseLayer *layer = (DenseLayer *)malloc(sizeof(DenseLayer));
    if (layer == NULL)
    {
        return NULL;
    }
    layer->in_features = in_features;
    layer->out_features = out_features;

    layer->weights = (float *)malloc(in_features * out_features * sizeof(float));
    layer->biases = (float *)calloc(out_features, sizeof(float));

    layer->dB = (float *)calloc(out_features, sizeof(float));
    layer->dW = (float *)calloc(in_features * out_features, sizeof(float));

    if (layer->weights == NULL || layer->biases == NULL || layer->dB == NULL || layer->dW == NULL)
    {
        dense_layer_free(layer);
        return NULL;
    }
    return layer;
}

void dense_layer_free(DenseLayer *layer)
{
    if (layer == NULL)
    {
        return;
    }
    if (layer->biases)
        free(layer->biases);
    if (layer->weights)
        free(layer->weights);
    if (layer->dB)
        free(layer->dB);
    if (layer->dW)
    
        free(layer->dW);
    free(layer);
}
