#include "transformer/layers/linear.h"
#include "transformer/matrix/matrix.h"
#include "transformer/memory/allocator.h"
#include "transformer/utils/random.h"
#include <stdio.h>

LinearLayer *layer_linear_create(size_t in_features, size_t out_features) {
  LinearLayer *layer = (LinearLayer *)memory_malloc(sizeof(LinearLayer));
  if (layer == NULL) {
    fprintf(stderr, "Failed to allocate memory for linear layer\n");
    return NULL;
  }

  layer->in_features = in_features;
  layer->out_features = out_features;

  layer->weights = matrix_create(in_features, out_features);
  if (layer->weights == NULL) {
    fprintf(stderr, "Failed to allocate memory for linear layer weights\n");
    memory_free(layer);
    return NULL;
  }

  layer->bias = (float *)memory_malloc(out_features * sizeof(float));
  if (layer->bias == NULL) {
    fprintf(stderr, "Failed to allocate memory for linear layer bias\n");
    matrix_free(layer->weights);
    memory_free(layer);
    return NULL;
  }

  random_uniform(layer->weights->data,
                 layer->weights->rows * layer->weights->cols, -1.0f, 1.0f);
  random_uniform(layer->bias, layer->out_features, -1.0f, 1.0f);

  return layer;
}

void layer_linear_free(LinearLayer *layer) {
  if (layer == NULL) {
    fprintf(stderr, "Linear layer is null\n");
    return;
  }

  matrix_free(layer->weights);
  memory_free(layer->bias);
  memory_free(layer);
}

void layer_linear_forward(Matrix *output, const Matrix *input,
                          const LinearLayer *layer) {
  matrix_multiply(output, input, layer->weights);
  matrix_add_scalar(output, layer->bias);
}
