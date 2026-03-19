#include "transformer/utils/random.h"
#include <stdlib.h>

void random_uniform(float *data, size_t size, float min, float max) {
  for (size_t i = 0; i < size; i++) {
    data[i] = (float)rand() / (float)RAND_MAX * (max - min) + min;
  }
}
