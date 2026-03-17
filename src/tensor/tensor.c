#include "transformer/tensor/tensor.h"
#include "transformer/memory/allocator.h"
#include <stdlib.h>
#include <string.h>

Tensor *tensor_create(size_t ndim, size_t *shape) {
  if (ndim == 0 || shape == NULL) {
    return NULL;
  }

  Tensor *tensor = (Tensor *)memory_malloc(sizeof(Tensor));
  if (tensor == NULL) {
    fprintf(stderr, "Failed to allocate memory for tensor\n");
    return NULL;
  }

  tensor->ndim = ndim;

  tensor->shape = (size_t *)memory_malloc(ndim * sizeof(size_t));
  if (tensor->shape == NULL) {
    fprintf(stderr, "Failed to allocate memory for tensor shape\n");
    memory_free(tensor);
    return NULL;
  }

  // Copy the shape array into the tensor's shape array.
  memory_copy(tensor->shape, shape, ndim * sizeof(size_t));

  size_t size = 1;
  for (size_t i = 0; i < ndim; i++) {
    size *= shape[i];
  }
  tensor->size = size;

  tensor->data = (float *)memory_calloc(size, sizeof(float));
  if (tensor->data == NULL) {
    fprintf(stderr, "Failed to allocate memory for tensor data\n");
    memory_free(tensor->shape);
    memory_free(tensor);
    return NULL;
  }

  return tensor;
}

void tensor_destroy(Tensor *tensor) {
  if (tensor != NULL) {
    if (tensor->data != NULL) {
      memory_free(tensor->data);
    }
    if (tensor->shape != NULL) {
      memory_free(tensor->shape);
    }
    memory_free(tensor);
  }
}

void tensor_fill(Tensor *tensor, float value) {
  if (tensor == NULL || tensor->data == NULL) {
    return;
  }

  for (size_t i = 0; i < tensor->size; i++) {
    tensor->data[i] = value;
  }
}

void tensor_fill_random(Tensor *tensor) {
  if (tensor == NULL || tensor->data == NULL) {
    return;
  }

  for (size_t i = 0; i < tensor->size; i++) {
    tensor->data[i] = (float)rand() / (float)RAND_MAX;
  }
}

void tensor_free(Tensor *tensor) {
  if (tensor != NULL) {
    if (tensor->data != NULL) {
      memory_free(tensor->data);
      tensor->data = NULL;
    }
  }
}
