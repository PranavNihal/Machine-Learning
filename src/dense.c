#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include <math.h>

DenseLayer *dense_layer_create(int in_features, int out_features)
{
    if (in_features <= 0 || out_features <= 0)
    {
        return 0;
    }
    DenseLayer *layer = (DenseLayer *)malloc(sizeof(DenseLayer));
    if (layer == NULL)
    {
        perror("malloc");
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
    {
        free(layer->biases);
    }   
    
    if (layer->weights)
    {
        free(layer->weights);
    }
    if (layer->dB)
    {
        free(layer->dB);
    }
    
    if (layer->dW)
    {
        free(layer->dW);
    }

    free(layer);
}

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

/**
 * @brief Performs backpropagation for a dense (fully connected) layer.
 *
 * @param X        Input matrix from forward pass (M x K)
 * @param W        Weight matrix (K x N)
 * @param d_out    Incoming gradient matrix (M x N)
 * @param dW       Buffer to store computed weight gradients (K x N)
 * @param dB       Buffer to store computed bias gradients (1 x N)
 * @param dX       Buffer to store computed input gradients (M x K)
 * @param M        Batch size (rows of X and d_out)
 * @param K        Input feature size (cols of X, rows of W)
 * @param N        Output feature size (cols of W and d_out)
 * @return int     0 on success, -1 / -2 on invalid inputs
 * in words, the X matrix is gotten from the forwards pass, and then we have its corresponding weight matrix
 * we have our d_out which essentially functions as a complaint/ error we have gotten from the original target
 * that we wanted. paramters dW is the adjustment for the Weight, parameter dB is the adjustment for the bias
 * and paramater dX is the adjustment for the inputs that have entered this layer. M, K and N are the necessary
 * details needed, the implementation behind these paramters will be added later on.
 */
int backward(const float *X, const float *W, const float *d_out, float *dW, float *dB, float *dX, int M, int K, int N)
{
    if (X == NULL || W == NULL || d_out == NULL || dW == NULL || dX == NULL || dB == NULL)
    {
        return -1;
    }
    // invalid parameters
    if (M <= 0 || K <= 0 || N <= 0)
    {
        return -2;
    }

    // Compute dW (Weight Gradients)
    for (int k = 0; k < K; k++)
    {
        for (int j = 0; j < N; j++)
        {
            float sum = 0.0f;
            for (int i = 0; i < M; i++)
            {
                sum += X[i * K + k] * d_out[i * N + j]; // Fixed: i * K + k
            }
            dW[k * N + j] = sum;
        }
    }

    // Compute dB (Bias Gradients)
    for (int j = 0; j < N; j++)
    {
        float sum = 0.0f;
        for (int i = 0; i < M; i++)
        {
            sum += d_out[i * N + j];
        }
        dB[j] = sum;
    }

    // Compute dX (Input Gradients)
    for (int i = 0; i < M; i++)
    {
        for (int k = 0; k < K; k++)
        {
            float sum = 0.0f;
            for (int j = 0; j < N; j++)
            {
                sum += d_out[i * N + j] * W[k * N + j];
            }
            dX[i * K + k] = sum;
        }
    }

    return 0;
}

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