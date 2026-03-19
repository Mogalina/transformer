#ifndef LINEAR_H
#define LINEAR_H

#include "../matrix/matrix.h"
#include <stddef.h>

/**
 * @brief Fully connected (dense) layer.
 *
 * A linear layer applies a linear transformation to the input. This is used to
 * transform the input to a different space. It is the most basic layer in a
 * neural network.
 *
 * @note input: (batch x in_features)
 * @note output: (batch x out_features)
 * @note weights: (in_features x out_features)
 * @note bias: (out_features)
 */
typedef struct {
  // Number of input features. This is the number of columns in the input
  // matrix.
  size_t in_features;

  // Number of output features. This is the number of columns in the output
  // matrix.
  size_t out_features;

  // Weight matrix of shape (in_features x out_features). Weights represent the
  // transformation matrix.
  Matrix *weights;

  // Bias vector of shape (out_features). Bias is added to the output of the
  // weight matrix.
  float *bias;
} LinearLayer;

/**
 * @brief Creates a new linear layer.
 *
 * @param in_features Number of input features.
 * @param out_features Number of output features.
 * @return Pointer to the newly created linear layer.
 */
LinearLayer *layer_linear_create(size_t in_features, size_t out_features);

/**
 * @brief Frees the memory allocated for a linear layer.
 *
 * @param layer Pointer to the linear layer to free.
 */
void layer_linear_free(LinearLayer *layer);

/**
 * @brief Performs a forward pass through the linear layer.
 *
 * @param output Pointer to the output matrix.
 * @param input Pointer to the input matrix.
 * @param layer Pointer to the linear layer.
 */
void layer_linear_forward(Matrix *output, const Matrix *input,
                          const LinearLayer *layer);

#endif
