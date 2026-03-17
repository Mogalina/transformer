#ifndef TENSOR_SHAPE_H
#define TENSOR_SHAPE_H

#include <stddef.h>

/**
 * @brief Computes the total size of a tensor given its shape and number of
 * dimensions.
 *
 * @param shape Array of dimension sizes.
 * @param dims Number of dimensions.
 * @return Total size of the tensor.
 */
size_t tensor_compute_size(const size_t *shape, size_t dims);

/**
 * @brief Copies the shape array.
 *
 * @param shape Array of dimension sizes.
 * @param dims Number of dimensions.
 * @return Copy of the shape array.
 */
size_t *tensor_shape_copy(const size_t *shape, size_t dims);

#endif
