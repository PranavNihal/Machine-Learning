// This is only a .c for the purpose of testing ;)
#include <stdio.h>
#include "matrix.h"

int main()
{
    // 2x2 Input Matrix (X)
    int X[4] = {1, -2,
                3, 4};

    // 2x2 Weight Matrix (W)
    int W[4] = {2, 0,
                -1, 1};

    // 1. Compute Z = X * W
    int *Z = matrix_multiply(X, 2, 2, W, 2, 2);

    printf("--- Output Matrix Z (X * W) ---\n");
    if (Z != NULL)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                printf("%d\t", Z[i * 2 + j]);
            }
            printf("\n");
        }
    }

    // 2. Compute Activation A = RELU(Z)
    int *A = RELU(Z, 2, 2);

    printf("\n--- Output Matrix A after ReLU ---\n");
    if (A != NULL)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                printf("%d\t", A[i * 2 + j]);
            }
            printf("\n");
        }
    }

    // Free memory
    free_matrix(Z);
    free_matrix(A);

    return 0;
}
// All functions including matrix multiplication, addition, subtraction and Transpose are working along with RELU and Matrix creation