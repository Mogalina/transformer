#include "transformer/math/stats.h"
#include <math.h>
#include <stdio.h>

float mean(const float *data, size_t size) {
  if (data == NULL) {
    fprintf(stderr, "Vector pointer is null\n");
    return 0;
  }

  float sum = 0;
  for (size_t i = 0; i < size; i++) {
    sum += data[i];
  }

  return sum / size;
}

float variance(const float *data, size_t size) {
  if (data == NULL) {
    fprintf(stderr, "Vector pointer is null\n");
    return 0;
  }

  float mean = mean(data, size);
  float sum = 0;
  for (size_t i = 0; i < size; i++) {
    sum += (data[i] - mean) * (data[i] - mean);
  }

  return sum / size;
}

float stddev(const float *data, size_t size) {
  if (data == NULL) {
    fprintf(stderr, "Vector pointer is null\n");
    return 0;
  }

  return sqrt(variance(data, size));
}

float max_value(const float *data, size_t size) {
  if (data == NULL) {
    fprintf(stderr, "Vector pointer is null\n");
    return 0;
  }

  float max = data[0];
  for (size_t i = 1; i < size; i++) {
    if (data[i] > max) {
      max = data[i];
    }
  }

  return max;
}

float min_value(const float *data, size_t size) {
  if (data == NULL) {
    fprintf(stderr, "Vector pointer is null\n");
    return 0;
  }

  float min = data[0];
  for (size_t i = 1; i < size; i++) {
    if (data[i] < min) {
      min = data[i];
    }
  }

  return min;
}
