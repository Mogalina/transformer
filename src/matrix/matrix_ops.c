#include "transformer/matrix/matrix_ops.h"
#include <math.h>

void matrix_multiply(Matrix *result, const Matrix *left, const Matrix *right) {
  if (left->cols != right->rows) {
    fprintf(stderr, "Incompatible matrix dimensions for multiplication\n");
    return;
  }

  for (size_t i = 0; i < left->rows; i++) {
    for (size_t j = 0; j < right->cols; j++) {
      float sum = 0;
      for (size_t k = 0; k < left->cols; k++) {
        sum +=
            left->data[i * left->cols + k] * right->data[k * right->cols + j];
      }
      result->data[i * result->cols + j] = sum;
    }
  }
}

void matrix_add(Matrix *result, const Matrix *left, const Matrix *right) {
  if (left->rows != right->rows || left->cols != right->cols) {
    fprintf(stderr, "Incompatible matrix dimensions for addition\n");
    return;
  }

  for (size_t i = 0; i < left->rows; i++) {
    for (size_t j = 0; j < left->cols; j++) {
      result->data[i * result->cols + j] =
          left->data[i * left->cols + j] + right->data[i * right->cols + j];
    }
  }
}

void matrix_transpose(Matrix *result, const Matrix *matrix) {
  if (result->rows != matrix->cols || result->cols != matrix->rows) {
    fprintf(stderr, "Incompatible matrix dimensions for transpose\n");
    return;
  }

  for (size_t i = 0; i < matrix->rows; i++) {
    for (size_t j = 0; j < matrix->cols; j++) {
      result->data[j * result->cols + i] = matrix->data[i * matrix->cols + j];
    }
  }
}

void matrix_softmax(Matrix *matrix) {
  for (size_t i = 0; i < matrix->rows; i++) {
    for (size_t j = 0; j < matrix->cols; j++) {
      matrix->data[i * matrix->cols + j] =
          exp(matrix->data[i * matrix->cols + j]);
    }
  }

  for (size_t i = 0; i < matrix->rows; i++) {
    for (size_t j = 0; j < matrix->cols; j++) {
      matrix->data[i * matrix->cols + j] /= matrix->rows;
    }
  }
}
