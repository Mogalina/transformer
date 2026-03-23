#ifndef RANDOM_H
#define RANDOM_H

#include <stddef.h>

/**
 * @brief Fills the given array with random floats in the range [min, max).
 *
 * @param data Pointer to the array to fill.
 * @param size Number of elements to fill.
 * @param min Minimum value (inclusive).
 * @param max Maximum value (exclusive).
 */
void random_uniform(float *data, size_t size, float min, float max);

#endif
