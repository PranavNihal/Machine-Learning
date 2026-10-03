#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int *create_matrix(int rows, int cols)

{
    if (rows <= 0 || cols <= 0)
    {
        return NULL;
    }
    int *matrix = calloc((cols * rows), sizeof(int));
    if (matrix == NULL)
    {
        return NULL;
    }
    return matrix;
}

void free_matrix(int *matrix)
{
    if (matrix == NULL)
    {
        return;
    }
    else
    {
        free(matrix);
    }
    return;
}

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

int *matrix_sub(const int *A, int rows_A, int cols_A, const int *B, int rows_B, int cols_B)
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
        result[i] = A[i] - B[i];
    }
    return result;
}

int *matrix_scalar(const int *array, int rows, int cols, int scalar)
{
    if (array == NULL || rows <= 0 || cols <= 0)
    {
        return NULL;
    }

    int *scalartmatrix = create_matrix(rows, cols);
    if (scalartmatrix == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < (rows * cols); i++)
    {
        scalartmatrix[i] = array[i] * scalar;
    }
    return scalartmatrix;
}

int *matrix_transpose(const int *Array, int rows, int cols)
{
    if (Array == NULL || rows <= 0 || cols <= 0)
    {
        return NULL;
    }
    int *transpose = create_matrix(cols, rows);
    if (transpose == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j * rows + i] = Array[i * cols + j];
        }
    }
    return transpose;
}
int *matrix_multiply(const int *A, int rows_A, int cols_A, const int *B, int rows_B, int cols_B)
{
    if (cols_A != rows_B || A == NULL || B == NULL)
    {
        // Matrix multiplicationn is rendered invalid in the case this conditions is not satisfied.
        return NULL;
    }
    int *result = create_matrix(rows_A, cols_B);
    if (result == NULL)
    {
        return NULL;
    }
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

int *matrix_bias(const int *M, int rows, int cols, const int *B)
{
    if (rows <= 0 || cols <= 0 || M == NULL || B == NULL)
    {
        return NULL;
    }
    int *bias = create_matrix(rows, cols);
    if (bias == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int index = i * cols + j;
            bias[index] = M[index] + B[j];
        }
    }
    return bias;
}
