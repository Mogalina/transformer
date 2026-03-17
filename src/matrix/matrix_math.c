#include "transformer/matrix/matrix_math.h"
#include "transformer/matrix/matrix.h"
#include <math.h>

void matrix_relu(Matrix *matrix) {
  size_t size = matrix->rows * matrix->cols;

  for (size_t i = 0; i < size; i++) {
    matrix->data[i] = fmax(matrix->data[i], 0);
  }
}

void matrix_gelu(Matrix *matrix) {
  size_t size = matrix->rows * matrix->cols;

  for (size_t i = 0; i < size; i++) {
    matrix->data[i] =
        0.5 * matrix->data[i] * (1 + erf(matrix->data[i] / sqrt(2)));
  }
}

void matrix_scale(Matrix *matrix, float scalar) {
  size_t size = matrix->rows * matrix->cols;

  for (size_t i = 0; i < size; i++) {
    matrix->data[i] *= scalar;
  }
}

void matrix_add_bias(Matrix *matrix, const float *bias) {
  size_t size = matrix->rows * matrix->cols;

  for (size_t i = 0; i < size; i++) {
    matrix->data[i] += bias[i % matrix->cols];
  }
}

void matrix_row_normalize(Matrix *matrix) {
  size_t size = matrix->rows * matrix->cols;

  for (size_t i = 0; i < size; i++) {
    float sum = 0;
    for (size_t j = 0; j < matrix->cols; j++) {
      sum += matrix->data[i * matrix->cols + j];
    }
    for (size_t j = 0; j < matrix->cols; j++) {
      matrix->data[i * matrix->cols + j] /= sum;
    }
  }
}

void matrix_apply_mask(Matrix *matrix, const int *mask) {
  size_t size = matrix->rows * matrix->cols;

  for (size_t i = 0; i < size; i++) {
    if (mask[i] == 0) {
      matrix->data[i] = -INFINITY;
    }
  }
}
