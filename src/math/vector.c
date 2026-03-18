#include "transformer/math/vector.h"
#include <math.h>
#include <stddef.h>
#include <stdio.h>

float vector_dot(const float *left, const float *right, size_t size) {
  if (left == NULL || right == NULL) {
    fprintf(stderr, "Vector pointers is NULL\n");
    return 0;
  }

  float result = 0;
  for (size_t i = 0; i < size; i++) {
    result += left[i] * right[i];
  }

  return result;
}

void vector_add(float *out, const float *left, const float *right,
                size_t size) {
  if (left == NULL || right == NULL || out == NULL) {
    fprintf(stderr, "Vector pointers is null\n");
    return;
  }

  for (size_t i = 0; i < size; i++) {
    out[i] = left[i] + right[i];
  }
}

void vector_add_inplace(float *left, const float *right, size_t size) {
  if (left == NULL || right == NULL) {
    fprintf(stderr, "Vector pointers is null\n");
    return;
  }

  for (size_t i = 0; i < size; i++) {
    left[i] += right[i];
  }
}

void vector_sub(float *out, const float *left, const float *right,
                size_t size) {
  if (left == NULL || right == NULL || out == NULL) {
    fprintf(stderr, "Vector pointers is null\n");
    return;
  }

  for (size_t i = 0; i < size; i++) {
    out[i] = left[i] - right[i];
  }
}

void vector_mul(float *out, const float *left, const float *right,
                size_t size) {
  if (left == NULL || right == NULL || out == NULL) {
    fprintf(stderr, "Vector pointers is null\n");
    return;
  }

  for (size_t i = 0; i < size; i++) {
    out[i] = left[i] * right[i];
  }
}

void vector_mul_inplace(float *left, const float *right, size_t size) {
  if (left == NULL || right == NULL) {
    fprintf(stderr, "Vector pointers is null\n");
    return;
  }

  for (size_t i = 0; i < size; i++) {
    left[i] *= right[i];
  }
}

void vector_scale(float *data, float scalar, size_t size) {
  if (data == NULL) {
    fprintf(stderr, "Vector pointers is null\n");
    return;
  }

  for (size_t i = 0; i < size; i++) {
    data[i] *= scalar;
  }
}

void vector_copy(float *dest, const float *src, size_t size) {
  if (dest == NULL || src == NULL) {
    fprintf(stderr, "Vector pointers is null\n");
    return;
  }

  for (size_t i = 0; i < size; i++) {
    dest[i] = src[i];
  }
}

void vector_fill(float *data, float value, size_t size) {
  if (data == NULL) {
    fprintf(stderr, "Vector pointers is null\n");
    return;
  }

  for (size_t i = 0; i < size; i++) {
    data[i] = value;
  }
}

float vector_sum(const float *data, size_t size) {
  if (data == NULL) {
    fprintf(stderr, "Vector pointers is null\n");
    return 0;
  }

  float result = 0;
  for (size_t i = 0; i < size; i++) {
    result += data[i];
  }

  return result;
}
