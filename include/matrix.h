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

// --- Layer Operations ---
DenseLayer *dense_layer_create(int in_features, int out_features);
void dense_layer_free(DenseLayer *layer);
void weight_init(DenseLayer *layer);
void forward_pass(DenseLayer *layer, const float *X, float *out, int M);
int backward(const float *X, const float *W, const float *d_out, float *dW, float *dB, float *dX, int M, int K, int N);
int dense_layer_backward(DenseLayer *layer, const float *X, const float *d_out, float *dX, int M);

// --- Activations ---
void relu_forward(const float *in, float *out, int size);
void relu_backward(const float *in, const float *d_out, float *d_in, int size);
void sigmoid_forward(const float *in, float *out, int size);
int sigmoid_derivative(const float *sigmoid_out, const float *d_out, float *d_in, int size);
void softmax_forward(const float *in, float *out, int rows, int cols);
int softmax_derivative(const float *softmax_out, const float *d_out, float *d_in, int size);

// --- Loss Functions ---
float MSE_Loss(const float *predictions, const float *targets, int size);
void mse_der(const float *predictions, const float *targets, float *d_out, int size);
float cross_entropy_loss(const float *y_pred, const float *y_true, float *d_out, int num_samples, int num_classes);

// --- Optimizers ---
void sgd(float *params, const float *grads, float lr, int size, int M);
void sgd_update_layer(DenseLayer *layer, float lr, int M);

// --- Core Matrix Math ---
int *create_matrix(int rows, int cols);
void free_matrix(int *matrix);
int *matrix_add(const int *A, int rows_A, int cols_A, const int *B, int rows_B, int cols_B);
int *matrix_sub(const int *A, int rows_A, int cols_A, const int *B, int rows_B, int cols_B);
int *matrix_scalar(const int *array, int rows, int cols, int scalar);
int *matrix_transpose(const int *Array, int rows, int cols);
int *matrix_multiply(const int *A, int rows_A, int cols_A, const int *B, int rows_B, int cols_B);
int *matrix_bias(const int *M, int rows, int cols, const int *B);

#endif