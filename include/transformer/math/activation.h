#ifndef ACTIVATION_H
#define ACTIVATION_H

#include <stddef.h>

/**
 * @brief Applies the Rectified Linear Unit (ReLU) activation function to a
 * vector.
 *
 * @param data The vector to apply the activation function to.
 * @param size The size of the vector.
 */
void activation_relu(float *data, size_t size);

/**
 * @brief Applies the Gaussian Error Linear Unit (GELU) activation function to a
 * vector.
 *
 * @param data The vector to apply the activation function to.
 * @param size The size of the vector.
 */
void activation_gelu(float *data, size_t size);

/**
 * @brief Applies the sigmoid activation function to a vector.
 *
 * @param data The vector to apply the activation function to.
 * @param size The size of the vector.
 */
void activation_sigmoid(float *data, size_t size);

/**
 * @brief Applies the tanh activation function to a vector.
 *
 * @param data The vector to apply the activation function to.
 * @param size The size of the vector.
 */
void activation_tanh(float *data, size_t size);

#endif
