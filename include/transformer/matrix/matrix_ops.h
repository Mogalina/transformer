#ifndef MATRIX_OPS_H
#define MATRIX_OPS_H

#include "matrix.h"

/**
 * @brief Multiplies two matrices.
 *
 * @param result The resulting matrix.
 * @param left The left matrix.
 * @param right The right matrix.
 */
void matrix_multiply(Matrix *result, const Matrix *left, const Matrix *right);

/**
 * @brief Adds two matrices.
 *
 * @param result The resulting matrix.
 * @param left The left matrix.
 * @param right The right matrix.
 */
void matrix_add(Matrix *result, const Matrix *left, const Matrix *right);

/**
 * @brief Transposes a matrix.
 *
 * A matrix is transposed by swapping its rows and columns. This is useful for
 * matrix multiplication when matrix dimensions are not compatible for
 * multiplication.
 *
 * @param result The resulting matrix.
 * @param matrix The matrix to transpose.
 */
void matrix_transpose(Matrix *result, const Matrix *matrix);

/**
 * @brief Applies softmax to a matrix.
 *
 * Softmax is a function that converts a vector of numbers into a probability
 * distribution. The probabilities sum up to 1.
 *
 * @param matrix The matrix to apply softmax to.
 */
void matrix_softmax(Matrix *matrix);

#endif
