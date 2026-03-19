#include "transformer/math/normalize.h"
#include <stdio.h>

void normalize_layer(float *data, size_t size, float epsilon) {
  if (data == NULL) {
    fprintf(stderr, "Vector pointer is null\n");
    return;
  }

  float mean = 0;
  for (size_t i = 0; i < size; i++) {
    mean += data[i];
  }
  mean /= size;

  float variance = 0;
  for (size_t i = 0; i < size; i++) {
    variance += (data[i] - mean) * (data[i] - mean);
  }
  variance /= size;

  for (size_t i = 0; i < size; i++) {
    data[i] = (data[i] - mean) / sqrt(variance + epsilon);
  }
}

void normalize_layer_affine(float *data, const float *gamma, const float *beta,
                            size_t size, float epsilon) {
  if (data == NULL || gamma == NULL || beta == NULL) {
    fprintf(stderr, "Vector pointer is null\n");
    return;
  }

  float mean = 0;
  for (size_t i = 0; i < size; i++) {
    mean += data[i];
  }
  mean /= size;

  float variance = 0;
  for (size_t i = 0; i < size; i++) {
    variance += (data[i] - mean) * (data[i] - mean);
  }
  variance /= size;

  for (size_t i = 0; i < size; i++) {
    data[i] = (data[i] - mean) / sqrt(variance + epsilon);
    data[i] = data[i] * gamma[i] + beta[i];
  }
}
