#include <stdio.h>
#include "matrix.h"
#include <stdlib.h>
#include <math.h>
int sigmoid_derivative(const float *sigmoid_out, const float *d_out, float *d_in, int size)
{
    if (sigmoid_out == NULL || d_out == NULL || d_in == NULL || size <= 0)
    {
        return -1;
        for (int i = 0; i < size; i++)
        {
            float a = sigmoid_out[i];

            d_in[i] = d_out[i] * a * (1.0f - a);
        }

        return 0;
    }
}