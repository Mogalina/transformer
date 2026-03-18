#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

/**
 * @brief Computes the dot product of two vectors.
 *
 * @param left The left vector.
 * @param right The right vector.
 * @param size The size of the vectors.
 * @return The dot product of the two vectors.
 */
float vector_dot(const float *left, const float *right, size_t size);

/**
 * @brief Adds two vectors element-wise.
 *
 * @param out The output vector.
 * @param left The left vector.
 * @param right The right vector.
 * @param size The size of the vectors.
 */
void vector_add(float *out, const float *left, const float *right, size_t size);

/**
 * @brief Adds two vectors element-wise in place.
 *
 * @param left The left vector.
 * @param right The right vector.
 * @param size The size of the vectors.
 */
void vector_add_inplace(float *left, const float *right, size_t size);

/**
 * @brief Subtracts two vectors element-wise.
 *
 * @param out The output vector.
 * @param left The left vector.
 * @param right The right vector.
 * @param size The size of the vectors.
 */
void vector_sub(float *out, const float *left, const float *right, size_t size);

/**
 * @brief Multiplies two vectors element-wise.
 *
 * @param out The output vector.
 * @param left The left vector.
 * @param right The right vector.
 * @param size The size of the vectors.
 */
void vector_mul(float *out, const float *left, const float *right, size_t size);

/**
 * @brief Multiplies two vectors element-wise in place.
 *
 * @param left The left vector.
 * @param right The right vector.
 * @param size The size of the vectors.
 */
void vector_mul_inplace(float *left, const float *right, size_t size);

/**
 * @brief Scales a vector by a scalar.
 *
 * @param data The vector to scale.
 * @param scalar The scalar to scale the vector by.
 * @param size The size of the vector.
 */
void vector_scale(float *data, float scalar, size_t size);

/**
 * @brief Copies a vector.
 *
 * @param dest The destination vector.
 * @param src The source vector.
 * @param size The size of the vector.
 */
void vector_copy(float *dest, const float *src, size_t size);

/**
 * @brief Fills a vector with a value.
 *
 * @param data The vector to fill.
 * @param value The value to fill the vector with.
 * @param size The size of the vector.
 */
void vector_fill(float *data, float value, size_t size);

/**
 * @brief Computes the sum of a vector.
 *
 * @param data The vector to sum.
 * @param size The size of the vector.
 * @return The sum of the vector.
 */
float vector_sum(const float *data, size_t size);

#endif
