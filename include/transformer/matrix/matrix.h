#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>

/**
 * @brief Matrix representation.
 */
typedef struct {
  // Pointer to the matrix data. This single dimensional array stores the matrix
  // data in row-major order.
  float *data;

  // Total number of rows in the matrix.
  size_t rows;

  // Total number of columns in the matrix.
  size_t cols;
} Matrix;

/**
 * @brief Creates a new matrix with the given dimensions.
 *
 * @param rows The number of rows.
 * @param cols The number of columns.
 * @return A pointer to the new matrix.
 */
Matrix *matrix_create(size_t rows, size_t cols);

/**
 * @brief Frees the memory allocated for the matrix.
 *
 * @param matrix A pointer to the matrix.
 */
void matrix_free(Matrix *matrix);

/**
 * @brief Fills the matrix with the given value.
 *
 * @param matrix A pointer to the matrix.
 * @param value The value to fill the matrix with.
 */
void matrix_fill(Matrix *matrix, float value);

/**
 * @brief Gets the value at the given row and column.
 *
 * @param matrix A pointer to the matrix.
 * @param row The row index.
 * @param col The column index.
 * @return The value at the given row and column.
 */
float matrix_get(const Matrix *matrix, size_t row, size_t col);

/**
 * @brief Sets the value at the given row and column.
 *
 * @param matrix A pointer to the matrix.
 * @param row The row index.
 * @param col The column index.
 * @param value The value to set.
 */
void matrix_set(Matrix *matrix, size_t row, size_t col, float value);

#endif
