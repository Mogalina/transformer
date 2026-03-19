#ifndef MATRIX_MATH_H
#define MATRIX_MATH_H

#include "matrix.h"

/**
 * Applies the Rectified Linear Unit (ReLU) activation function to the input
 * matrix.
 *
 * ReLU is used as an activation function in neural networks to introduce
 * non-linearity.
 *
 * @param matrix The input matrix.
 */
void matrix_relu(Matrix *matrix);

/**
 * Applies the Gaussian Error Linear Unit (GELU) activation function to the
 * input matrix.
 *
 * GELU is used as an activation function in neural networks to introduce
 * non-linearity.
 *
 * @param matrix The input matrix.
 */
void matrix_gelu(Matrix *matrix);

/**
 * Scales the input matrix by a scalar value.
 *
 * @param matrix The input matrix.
 * @param scalar The scalar value to scale the matrix by.
 */
void matrix_scale(Matrix *matrix, float scalar);

/**
 * Adds a bias vector to the input matrix.
 *
 * @param matrix The input matrix.
 * @param bias The bias vector to add to the matrix.
 */
void matrix_add_bias(Matrix *matrix, const float *bias);

/**
 * Row-normalizes the input matrix.
 *
 * Row-normalization is used to normalize the rows of a matrix to have unit
 * length.
 *
 * @param matrix The input matrix.
 */
void matrix_row_normalize(Matrix *matrix);

/**
 * Applies a mask to the input matrix.
 *
 * A mask is used to indicate which elements of a matrix should be used in a
 * computation.
 *
 * @param matrix The input matrix.
 * @param mask The mask to apply to the matrix.
 */
void matrix_apply_mask(Matrix *matrix, const int *mask);

#endif
