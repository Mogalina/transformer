#include "transformer/math/activation.h"
#include <math.h>
#include <stdio.h>

void activation_relu(float *data, size_t size) {
  if (data == NULL) {
    fprintf(stderr, "Vector pointer is null\n");
    return;
  }

  for (size_t i = 0; i < size; i++) {
    if (data[i] < 0) {
      data[i] = 0;
    }
  }
}

void activation_gelu(float *data, size_t size) {
  if (data == NULL) {
    fprintf(stderr, "Vector pointer is null\n");
    return;
  }

  for (size_t i = 0; i < size; i++) {
    data[i] = data[i] * 0.5 *
              (1 + tanh(sqrt(2 / M_PI) *
                        (data[i] + 0.044715 * data[i] * data[i] * data[i])));
  }
}

void activation_sigmoid(float *data, size_t size) {
  if (data == NULL) {
    fprintf(stderr, "Vector pointer is null\n");
    return;
  }

  for (size_t i = 0; i < size; i++) {
    data[i] = 1 / (1 + exp(-data[i]));
  }
}

void activation_tanh(float *data, size_t size) {
  if (data == NULL) {
    fprintf(stderr, "Vector pointer is null\n");
    return;
  }

  for (size_t i = 0; i < size; i++) {
    data[i] = tanh(data[i]);
  }
}
