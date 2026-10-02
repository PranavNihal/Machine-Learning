#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include <math.h>

void weight_init(DenseLayer *layer)
{
    if (layer == NULL || layer->weights == NULL)
    {
        return;
    }
    int tot_weights = layer->in_features * layer->out_features;
    float limit = sqrt(6.0f / (float)layer->in_features);

    for (int i = 0; i < tot_weights; i++)
    {
        float normalized = ((float)rand() / (float)RAND_MAX) * 2.0f - 1.0f;
        layer->weights[i] = normalized * limit;
    }
}