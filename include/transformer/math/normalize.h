#ifndef NORMALIZE_H
#define NORMALIZE_H

#include <stddef.h>

/**
 * @brief Applies layer normalization to a vector.
 *
 * Layer normalization is used for stabilizing the training of deep neural
 * networks. It is a technique that is used to normalize the output of a layer
 * to have zero mean and unit variance.
 *
 * @param data The vector to apply the layer normalization to.
 * @param size The size of the vector.
 * @param epsilon The epsilon value to use for the layer normalization.
 *
 * @note Normalization is done in-place.
 */
void normalize_layer(float *data, size_t size, float epsilon);

/**
 * @brief Applies layer normalization with scale and bias to a vector.
 *
 * Affine transformation is used to scale and shift the normalized output. It
 * allows the model to learn the optimal scale and shift for the normalized
 * output.
 *
 * @param data The vector to apply the layer normalization to.
 * @param gamma The scale parameter.
 * @param beta The bias parameter.
 * @param size The size of the vector.
 * @param epsilon The epsilon value to use for the layer normalization.
 */
void normalize_layer_affine(float *data, const float *gamma, const float *beta,
                            size_t size, float epsilon);

#endif
