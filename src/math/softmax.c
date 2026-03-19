#include "transformer/math/softmax.h"
#include <math.h>
#include <stdio.h>

void softmax(float *data, size_t size) {
  if (data == NULL) {
    fprintf(stderr, "Vector pointer is null\n");
    return;
  }

  float max = data[0];
  for (size_t i = 1; i < size; i++) {
    if (data[i] > max) {
      max = data[i];
    }
  }

  for (size_t i = 0; i < size; i++) {
    data[i] = exp(data[i] - max);
  }

  float sum = 0;
  for (size_t i = 0; i < size; i++) {
    sum += data[i];
  }

  for (size_t i = 0; i < size; i++) {
    data[i] /= sum;
  }
}

void softmax_out(const float *input, float *output, size_t size) {
  if (input == NULL || output == NULL) {
    fprintf(stderr, "Vector pointer is null\n");
    return;
  }

  float max = input[0];
  for (size_t i = 1; i < size; i++) {
    if (input[i] > max) {
      max = input[i];
    }
  }

  for (size_t i = 0; i < size; i++) {
    output[i] = exp(input[i] - max);
  }

  float sum = 0;
  for (size_t i = 0; i < size; i++) {
    sum += output[i];
  }

  for (size_t i = 0; i < size; i++) {
    output[i] /= sum;
  }
}

void softmax_rows(float *data, size_t rows, size_t cols) {
  if (data == NULL) {
    fprintf(stderr, "Vector pointer is null\n");
    return;
  }

  for (size_t i = 0; i < rows; i++) {
    softmax(data + i * cols, cols);
  }
}

void softmax_masked(float *data, const int *mask, size_t size) {
  if (data == NULL || mask == NULL) {
    fprintf(stderr, "Vector pointer is null\n");
    return;
  }

  float max = data[0];
  for (size_t i = 1; i < size; i++) {
    if (data[i] > max) {
      max = data[i];
    }
  }

  for (size_t i = 0; i < size; i++) {
    data[i] = exp(data[i] - max);
  }

  float sum = 0;
  for (size_t i = 0; i < size; i++) {
    sum += data[i];
  }

  for (size_t i = 0; i < size; i++) {
    data[i] /= sum;
  }
}

void softmax_masked_out(const float *input, float *output, const int *mask,
                        size_t size) {
  if (input == NULL || output == NULL || mask == NULL) {
    fprintf(stderr, "Vector pointer is null\n");
    return;
  }

  float max = input[0];
  for (size_t i = 1; i < size; i++) {
    if (input[i] > max) {
      max = input[i];
    }
  }

  for (size_t i = 0; i < size; i++) {
    output[i] = exp(input[i] - max);
  }

  float sum = 0;
  for (size_t i = 0; i < size; i++) {
    sum += output[i];
  }

  for (size_t i = 0; i < size; i++) {
    output[i] /= sum;
  }
}
