#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
 * @brief Free block of memory.
 *
 * Represents a free block of memory in the memory pool. When a block is free,
 * it is added to the free list.
 *
 * @note The block is stored in a singly linked list of free blocks.
 */
typedef struct FreeNode {
  // Pointer to the next free block of memory.
  struct FreeNode *next;
} FreeNode;

/**
 * @brief Memory pool structure.
 *
 * A fixed-size memory pool that allocates memory in fixed-size chunks.
 * This is useful for allocating many small objects of the same size. Avoids
 * fragmentation and makes allocation faster and predictable.
 *
 * @note The pool is not thread-safe. Use with caution in multi-threaded
 * environments.
 */
typedef struct {
  // Pointer to the memory pool.
  uint8_t *memory;

  // Size of each chunk in bytes.
  size_t chunk_size;

  // Total number of chunks in the pool.
  size_t capacity;

  // Head pointer to the free chunks list. Allocates memory in constant time
  // using a stack-like approach.
  FreeNode *free_chunks;
} MemoryPool;

/**
 * @brief Helper function to initialize the free list.
 *
 * @param free_list The free list to initialize.
 * @param chunk_size The size of each chunk in bytes.
 * @param capacity The number of chunks in the pool.
 * @return A pointer to the initialized free list.
 */
FreeNode *_init_free_list(FreeNode *free_list, size_t chunk_size,
                          size_t capacity);

/**
 * @brief Creates a new memory pool.
 *
 * @param chunk_size The size of each chunk in bytes.
 * @param capacity The number of chunks in the pool.
 * @return A pointer to the new memory pool, or NULL if allocation fails.
 */
MemoryPool *memory_pool_create(size_t chunk_size, size_t capacity);

/**
 * @brief Destroys a memory pool.
 *
 * @param pool The memory pool to destroy.
 */
void memory_pool_destroy(MemoryPool *pool);

/**
 * @brief Allocates memory from the pool.
 *
 * @param pool The memory pool to allocate from.
 * @return A pointer to the allocated memory, or NULL if the pool is full.
 */
void *memory_pool_alloc(MemoryPool *pool);

/**
 * @brief Free memory back to the pool.
 *
 * @param pool The memory pool to free memory to.
 * @param ptr The pointer to free.
 * @return true if the memory was successfully freed, false otherwise.
 */
bool memory_pool_free(MemoryPool *pool, void *ptr);

/**
 * @brief Get the number of free chunks in the pool.
 *
 * @param pool The memory pool.
 * @return The number of free chunks.
 */
size_t memory_pool_free_count(const MemoryPool *pool);

/**
 * @brief Get the total capacity of the pool.
 *
 * @param pool The memory pool.
 * @return The total capacity.
 */
size_t memory_pool_capacity(const MemoryPool *pool);

#endif
