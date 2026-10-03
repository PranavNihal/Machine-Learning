#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"
/* Different activation functions along with their backward passes.
RELU, Softmax, Sigmoid activations*/
void relu_forward(const float *in, float *out, int size)
{
    if (in == NULL || out == NULL || size <= 0)
    {
        return;
    }
    for (int i = 0; i < size; i++)
    {
        out[i] = (in[i] > 0.0f) ? in[i] : 0.0f;
    }
}

void relu_backward(const float *in, const float *d_out, float *d_in, int size)
{
    if (in == NULL || d_out == NULL || d_in == NULL || size <= 0)
    {
        return;
    }
    for (int i = 0; i < size; i++)
    {
        d_in[i] = (in[i] > 0.0f) ? d_out[i] : 0.0f;
    }
}

void sigmoid_forward(const float *in, float *out, int size)
{
    if (in == NULL || out == NULL || size <= 0)
    {
        return;
    }
    for (int i = 0; i < size; i++)
    {
        out[i] = 1.0f / (1.0f + expf(-in[i]));
    }
}

int sigmoid_derivative(const float *sigmoid_out, const float *d_out, float *d_in, int size)
{
    if (sigmoid_out == NULL || d_out == NULL || d_in == NULL || size <= 0)
    {
        return -1;
    }

    for (int i = 0; i < size; i++)
    {
        float a = sigmoid_out[i];
        d_in[i] = d_out[i] * a * (1.0f - a);
    }

    return 0;
}

void softmax_forward(const float *in, float *out, int rows, int cols)
{
    if (in == NULL || out == NULL || rows <= 0 || cols <= 0)
    {
        return;
    }

    for (int i = 0; i < rows; i++)
    {
        // Finding row maximum for numerical stability
        float max_val = in[i * cols];
        for (int j = 1; j < cols; j++)
        {
            if (in[i * cols + j] > max_val)
            {
                max_val = in[i * cols + j];
            }
        }

        float sum = 0.0f;
        for (int j = 0; j < cols; j++)
        {
            int idx = i * cols + j;
            out[idx] = expf(in[idx] - max_val);
            sum += out[idx];
        }

        for (int j = 0; j < cols; j++)
        {
            int idx = i * cols + j;
            out[idx] /= sum;
        }
    }
}

int softmax_derivative(const float *softmax_out, const float *d_out, float *d_in, int size)
{
    if (softmax_out == NULL || d_out == NULL || d_in == NULL || size <= 0)
    {
        return -1;
    }

    for (int i = 0; i < size; i++)
    {
        float grad_sum = 0.0f;

        for (int j = 0; j < size; j++)
        {
            float jacobian;
            if (i == j)
            {
                jacobian = softmax_out[i] * (1.0f - softmax_out[i]);
            }
            else
            {
                jacobian = -softmax_out[i] * softmax_out[j];
            }
            grad_sum += d_out[j] * jacobian;
        }

        d_in[i] = grad_sum;
    }

    return 0;
}