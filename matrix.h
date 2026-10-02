#ifndef MATRIX_H
#define MATRIX_H
typedef struct
{
    int in_features;
    int out_features;

    float *weights;
    float *biases;

    float *dW;
    float *dB;

} DenseLayer;
int *matrix_add(const int *A, int rows_A, int cols_A, const int *B, int rows_B, int cols_B);
int *create_matrix(int rows, int cols);
int *matrix_scalar(const int *array, int rows, int cols, int scalar);
int *matrix_multiply(const int *A, int rows_A, int cols_A, const int *B, int rows_B, int cols_B);
int *matrix_transpose(const int *array, int rows, int cols);
int *RELU(const int *array, int rows, int cols);
int *matrix_sub(const int *A, int rows_A, int cols_A, const int *B, int rows_B, int cols_B);
void free_matrix(int *matrix);

int backward(const float *X, const float *W, const float *d_out, float *dW, float *dB, float *dX, int K, int M, int N);
void sgd(float *params, float *grads, float lr, float size);

DenseLayer *dense_layer_create(int in_features, int out_features);
void dense_layer_free(DenseLayer *layer);
#endif