#ifndef TENSOR_H
#define TENSOR_H

#include <stddef.h>

/**
 * @brief Represents a tensor.
 *
 * A tensor is a multi-dimensional array of floating-point numbers.
 * It is used to store the weights and activations of the neural network.
 *
 * @note This is a simple implementation of a tensor. It does not support
 * advanced features such as striding, broadcasting, or automatic
 * differentiation.
 */
typedef struct {
  // Pointer to the tensor data.
  float *data;

  // Array of dimensions representing the shape of the tensor.
  size_t *shape;

  // Number of dimensions. This is the same as the length of the shape array.
  size_t ndim;

  // Size of the tensor. This is the calculated value of the product of the
  // dimensions.
  size_t size;
} Tensor;

/**
 * @brief Creates a new tensor.
 *
 * @param ndim The number of dimensions.
 * @param shape An array of dimensions.
 * @return A pointer to the new tensor, or NULL if allocation fails.
 */
Tensor *tensor_create(size_t ndim, size_t *shape);

/**
 * @brief Destroys a tensor.
 *
 * @param tensor The tensor to destroy.
 */
void tensor_destroy(Tensor *tensor);

/**
 * @brief Fills the tensor with a given value.
 *
 * @param tensor The tensor to fill.
 * @param value The value to fill the tensor with.
 */
void tensor_fill(Tensor *tensor, float value);

/**
 * @brief Fills the tensor with random values.
 *
 * @param tensor The tensor to fill.
 */
void tensor_fill_random(Tensor *tensor);

/**
 * @brief Frees the tensor.
 *
 * @param tensor The tensor to free.
 */
void tensor_free(Tensor *tensor);

#endif
