#include "transformer/tensor/tensor_shape.h"
#include "transformer/memory/allocator.h"
#include <stdio.h>

size_t tensor_compute_size(const size_t *shape, size_t dims) {
  size_t size = 1;
  for (size_t i = 0; i < dims; i++) {
    size *= shape[i];
  }
  return size;
}

size_t *tensor_shape_copy(const size_t *shape, size_t dims) {
  size_t *new_shape = (size_t *)memory_malloc(dims * sizeof(size_t));
  if (new_shape == NULL) {
    fprintf(stderr, "Failed to allocate memory for tensor shape\n");
    exit(EXIT_FAILURE);
  }

  memory_copy(new_shape, shape, dims * sizeof(size_t));
  return new_shape;
}
