#ifndef STATS_H
#define STATS_H

#include <stddef.h>

/**
 * @brief Computes the mean of a vector.
 *
 * The mean is computed as the sum of the elements of the vector divided by the
 * number of elements.
 *
 * @param data The vector to compute the mean of.
 * @param size The size of the vector.
 *
 * @return The mean of the vector.
 */
float stats_mean(const float *data, size_t size);

/**
 * @brief Computes the variance of a vector.
 *
 * The variance is computed as the mean of the squared differences between the
 * elements of the vector and the mean of the vector.
 *
 * @param data The vector to compute the variance of.
 * @param size The size of the vector.
 *
 * @return The variance of the vector.
 */
float stats_variance(const float *data, size_t size);

/**
 * @brief Computes the standard deviation of a vector.
 *
 * The standard deviation is computed as the square root of the variance. This
 * is a measure of the amount of variation or dispersion of a set of values.
 * This is used to normalize the data.
 *
 * @param data The vector to compute the standard deviation of.
 * @param size The size of the vector.
 *
 * @return The standard deviation of the vector.
 */
float stats_stddev(const float *data, size_t size);

/**
 * @brief Computes the maximum value of a vector.
 *
 * @param data The vector to compute the maximum value of.
 * @param size The size of the vector.
 *
 * @return The maximum value of the vector.
 */
float stats_max_value(const float *data, size_t size);

/**
 * @brief Computes the minimum value of a vector.
 *
 * @param data The vector to compute the minimum value of.
 * @param size The size of the vector.
 *
 * @return The minimum value of the vector.
 */
float stats_min_value(const float *data, size_t size);

#endif
