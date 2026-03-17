#include "transformer/matrix/matrix.h"
#include "transformer/memory/allocator.h"
#include <stdio.h>

Matrix *matrix_create(size_t rows, size_t cols) {
  Matrix *matrix = (Matrix *)memory_allocate(sizeof(Matrix));
  if (matrix == NULL) {
    fprintf(stderr, "Failed to allocate memory for matrix\n");
    return NULL;
  }

  matrix->rows = rows;
  matrix->cols = cols;

  matrix->data = (float *)memory_allocate(rows * cols * sizeof(float));
  if (matrix->data == NULL) {
    fprintf(stderr, "Failed to allocate memory for matrix data\n");
    memory_free(matrix);
    return NULL;
  }

  return matrix;
}

void matrix_free(Matrix *matrix) {
  if (matrix == NULL) {
    return;
  }

  if (matrix->data != NULL) {
    memory_free(matrix->data);
  }

  memory_free(matrix);
}

void matrix_fill(Matrix *matrix, float value) {
  if (matrix == NULL) {
    return;
  }

  for (size_t i = 0; i < matrix->rows * matrix->cols; i++) {
    matrix->data[i] = value;
  }
}

float matrix_get(const Matrix *matrix, size_t row, size_t col) {
  if (row >= matrix->rows || col >= matrix->cols) {
    fprintf(stderr, "Index out of bounds\n");
    return 0;
  }

  return matrix->data[row * matrix->cols + col];
}

void matrix_set(Matrix *matrix, size_t row, size_t col, float value) {
  if (row >= matrix->rows || col >= matrix->cols) {
    fprintf(stderr, "Index out of bounds\n");
    return;
  }

  matrix->data[row * matrix->cols + col] = value;
}
