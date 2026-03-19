#ifndef SOFTMAX_H
#define SOFTMAX_H

#include <stddef.h>

/**
 * @brief Applies the softmax function to a vector.
 *
 * @param data The vector to apply the softmax function to.
 * @param size The size of the vector.
 */
void softmax(float *data, size_t size);

/**
 * @brief Applies the softmax function to a vector.
 *
 * @param input The input vector.
 * @param output The output vector.
 * @param size The size of the vector.
 */
void softmax_out(const float *input, float *output, size_t size);

/**
 * @brief Applies the softmax function to a vector.
 *
 * @param data The vector to apply the softmax function to.
 * @param rows The number of rows.
 * @param cols The number of columns.
 */
void softmax_rows(float *data, size_t rows, size_t cols);

/**
 * @brief Applies the softmax function to a vector.
 *
 * @param data The vector to apply the softmax function to.
 * @param mask The mask to apply the softmax function to.
 * @param size The size of the vector.
 */
void softmax_masked(float *data, const int *mask, size_t size);

/**
 * @brief Applies the softmax function to a vector.
 *
 * @param input The input vector.
 * @param output The output vector.
 * @param mask The mask to apply the softmax function to.
 * @param size The size of the vector.
 */
void softmax_masked_out(const float *input, float *output, const int *mask,
                        size_t size);

#endif
