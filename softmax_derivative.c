#include <stdio.h>
#include <stdlib.h>

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