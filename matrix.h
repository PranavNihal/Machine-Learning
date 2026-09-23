#ifndef MATRIX_H
#define MATRIX_H
int *matrix_add(const int *A, int rows_A, int cols_A, const int *B, int rows_B, int cols_B);
int *create_matrix(int rows, int cols);
int *matrix_scalar(const int *array, int rows, int cols, int scalar);
int *matrix_multiply(const int *A, int rows_A, int cols_A, const int *B, int rows_B, int cols_B);
int *matrix_transpose(const int *array, int rows, int cols);
int *RELU(const int *array, int rows, int cols);
int *matrix_sub(const int *A, int rows_A, int cols_A, const int *B, int rows_B, int cols_B);
void free_matrix(int *matrix);
#endif