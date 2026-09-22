#include <stdio.h>
int *matrix_add(const int *A, int rows_A, int cols_A, const int *B, int rows_B, int cols_B)
{
    if (A == NULL || B == NULL || rows_A != rows_B || cols_A != cols_B)
    {
        return NULL;
    }

    int size = rows_A * cols_A;
    int *result = create_matrix(rows_A, cols_A);
    if (result == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < size; i++)
    {
        result[i] = A[i] + B[i];
    }
    return result;
}
