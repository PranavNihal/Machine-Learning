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
int *RELU(const int *array, int rows, int cols);
int *RELU_der(const int *array, int rows, int cols);

float MSE_Loss(const float *predictions, const float *targets, int size);
float *mse_der(const float *predictions, const float *targets, int size);
DenseLayer *dense_layer_create(int in_features, int out_features);
void dense_layer_free(DenseLayer *layer);

void forward_pass(DenseLayer *layer, const float *X, float *out, int M);

float cross_entropy_loss(const float *y_pred, const float *y_true, float *d_out, int num_samples, int num_classes);

int backward(const float *X, const float *W, const float *d_out, float *dW, float *dB, float *dX, int M, int K, int N);
int dense_layer_backward(DenseLayer *layer, const float *X, const float *d_out, float *dX, int M);

void sgd(float *params, const float *grads, float lr, int size, int M);
void sgd_update_layer(DenseLayer *layer, float lr, int M);

int *matrix_add(const int *A, int rows_A, int cols_A, const int *B, int rows_B, int cols_B);
int *create_matrix(int rows, int cols);
int *matrix_scalar(const int *array, int rows, int cols, int scalar);
int *matrix_multiply(const int *A, int rows_A, int cols_A, const int *B, int rows_B, int cols_B);
int *matrix_transpose(const int *array, int rows, int cols);
int *RELU(const int *array, int rows, int cols);
int *matrix_sub(const int *A, int rows_A, int cols_A, const int *B, int rows_B, int cols_B);
void free_matrix(int *matrix);

#endif