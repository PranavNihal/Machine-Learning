#include <stdio.h>
#include <stdlib.h>

void sgd(float *params, const float *grads, float lr, int size)
{
    if (params == NULL || grads == NULL || lr <= 0.0f || size <= 0)
    {
        return;
    }
    for (int i = 0; i < size; i++)
    {
        params[i] -= lr * grads[i];
    }
}