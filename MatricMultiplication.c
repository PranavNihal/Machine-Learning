#include <stdio.h>
#include "matrix.h"
int *matrix_multiply(const int *A, int rows_A, int cols_A, const int *B, int rows_B, int cols_B)
{
    if (cols_A != rows_B)
    {
        // Matrix multiplicationn is rendered invalid in the case this conditions is not satisfied.
        return NULL;
    }
    int *result = create_matrix(rows_A, cols_B);
    {
        for (int i = 0; i < rows_A; i++)
        {
            for (int j = 0; j < cols_B; j++)
            {
                int index_res = (i * cols_B) + j;
                result[index_res] = 0;
                // We can use rows_B instead of cols_A also because they are supposed to be equal
                for (int k = 0; k < cols_A; k++)
                {
                    int index1 = (i * cols_A) + k;
                    int index2 = (k * cols_B) + j;
                    result[index_res] += A[index1] * B[index2];
                }
            }
        }
    }
    return result;
}
