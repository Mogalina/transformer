#include "transformer/tensor/tensor_ops.h"
#include "transformer/memory/allocator.h"
#include <stdio.h>

void tensor_add(Tensor *out, const Tensor *tensor_1, const Tensor *tensor_2) {
  if (tensor_1->size != tensor_2->size || out->size != tensor_1->size) {
    fprintf(stderr, "Tensors must have the same size for addition\n");
    exit(EXIT_FAILURE);
  }

  for (size_t i = 0; i < tensor_1->size; i++) {
    out->data[i] = tensor_1->data[i] + tensor_2->data[i];
  }
}

void tensor_mul(Tensor *out, const Tensor *tensor_1, const Tensor *tensor_2) {
  if (tensor_1->size != tensor_2->size || out->size != tensor_1->size) {
    fprintf(stderr, "Tensors must have the same size for multiplication\n");
    exit(EXIT_FAILURE);
  }

  for (size_t i = 0; i < tensor_1->size; i++) {
    out->data[i] = tensor_1->data[i] * tensor_2->data[i];
  }
}

void tensor_scale(Tensor *tensor, float scalar) {
  for (size_t i = 0; i < tensor->size; i++) {
    tensor->data[i] *= scalar;
  }
}

void tensor_copy(Tensor *dest, const Tensor *src) {
  if (dest->size != src->size) {
    fprintf(stderr, "Tensors must have the same size for copying\n");
    exit(EXIT_FAILURE);
  }

  memory_copy(dest->data, src->data, src->size * sizeof(float));
}
