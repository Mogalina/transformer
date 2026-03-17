#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <stddef.h>

/**
 * @brief Allocates a block of memory of the specified size.
 *
 * This function is a safe wrapper around malloc() that checks if the allocation
 * was successful. If the allocation fails, it prints an error message and
 * terminates the execution.
 *
 * @param size The number of bytes to allocate.
 * @return A pointer to the allocated memory block.
 *
 * @note The returned memory is not initialized.
 * @note The returned pointer must be freed using safe_free().
 */
void *memory_malloc(size_t size);

/**
 * @brief Allocates a block of memory of the specified size.
 *
 * This function is a safe wrapper around calloc() that checks if the allocation
 * was successful. If the allocation fails, it prints an error message and
 * terminates the execution.
 *
 * @param count The number of elements to allocate.
 * @param size The size of each element.
 * @return A pointer to the allocated memory block.
 *
 * @note The returned memory is initialized to zero.
 * @note The returned pointer must be freed using safe_free().
 */
void *memory_calloc(size_t count, size_t size);

/**
 * @brief Reallocates a block of memory.
 *
 * This function is a safe wrapper around realloc() that checks if the
 * reallocation was successful. If the reallocation fails, it prints an error
 * message and terminates the execution.
 *
 * @param ptr A pointer to the memory block to reallocate.
 * @param size The new size of the memory block.
 * @return A pointer to the reallocated memory block.
 *
 * @note The returned memory is not initialized.
 * @note The returned pointer must be freed using safe_free().
 */
void *memory_realloc(void *ptr, size_t size);

/**
 * @brief Frees a block of memory.
 *
 * This function is a safe wrapper around free() that releases memory previously
 * allocated by safe_malloc(), safe_calloc(), or safe_realloc().
 *
 * @param ptr A pointer to the memory block to free.
 *
 * @note The pointer must point to a memory block in order to be freed.
 */
void memory_free(void *ptr);

#endif
