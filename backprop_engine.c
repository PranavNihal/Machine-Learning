#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
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
int bachward(const float *X, const float *W, const float *d_out, float *dW, float *dB, float *dX, int M, int K, int N)
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