#ifndef TENSOR_OPS_H
#define TENSOR_OPS_H

#include "tensor.h"

/**
 * @brief Adds two tensors element-wise.
 *
 * @param out Tensor to store the result.
 * @param tensor_1 First tensor.
 * @param tensor_2 Second tensor.
 */
void tensor_add(Tensor *out, const Tensor *tensor_1, const Tensor *tensor_2);

/**
 * @brief Multiplies two tensors element-wise.
 *
 * @param out Tensor to store the result.
 * @param tensor_1 First tensor.
 * @param tensor_2 Second tensor.
 */
void tensor_mul(Tensor *out, const Tensor *tensor_1, const Tensor *tensor_2);

/**
 * @brief Scales a tensor by a scalar.
 *
 * @param tensor Tensor to scale.
 * @param scalar Scalar to scale by.
 */
void tensor_scale(Tensor *tensor, float scalar);

/**
 * @brief Copies a tensor.
 *
 * @param dest Tensor to copy to.
 * @param src Tensor to copy from.
 */
void tensor_copy(Tensor *dest, const Tensor *src);

#endif
