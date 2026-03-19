#include "transformer/math/stats.h"
#include <math.h>
#include <stdio.h>

float stats_mean(const float *data, size_t size) {
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

float stats_variance(const float *data, size_t size) {
  if (data == NULL) {
    fprintf(stderr, "Vector pointer is null\n");
    return 0;
  }

  float mean = stats_mean(data, size);
  float sum = 0;
  for (size_t i = 0; i < size; i++) {
    sum += (data[i] - mean) * (data[i] - mean);
  }

  return sum / size;
}

float stats_stddev(const float *data, size_t size) {
  if (data == NULL) {
    fprintf(stderr, "Vector pointer is null\n");
    return 0;
  }

  return sqrt(stats_variance(data, size));
}

float stats_max_value(const float *data, size_t size) {
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

float stats_min_value(const float *data, size_t size) {
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
