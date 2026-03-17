#include "transformer/memory/memory_pool.h"
#include "transformer/memory/allocator.h"
#include <stdio.h>
#include <stdlib.h>

FreeNode *_init_free_list(FreeNode *free_list, size_t chunk_size,
                          size_t capacity) {
  // Get the memory address of the first chunk.
  uint8_t *byte_ptr = (uint8_t *)free_list;

  // Initialize the free list by linking all chunks together.
  for (size_t i = 0; i < capacity; i++) {
    // Get the current node.
    FreeNode *node = (FreeNode *)(byte_ptr + i * chunk_size);

    // If the node is not the last node, link it to the next node.
    if (i < capacity - 1) {
      node->next = (FreeNode *)(byte_ptr + (i + 1) * chunk_size);
    } else {
      // Set the last node's next pointer to NULL.
      node->next = NULL;
    }
  }

  return free_list;
}

MemoryPool *memory_pool_create(size_t chunk_size, size_t capacity) {
  // Ensure that the memory pool has available capacity.
  if (chunk_size == 0 || capacity == 0) {
    fprintf(stderr, "Memory pool creation failed\n");
    return NULL;
  }

  // Ensure chunk size is at least the size of a pointer to maintain the
  // integrity of the free list.
  if (chunk_size < sizeof(FreeNode)) {
    chunk_size = sizeof(FreeNode);
  }

  // Allocate memory for the pool structure itself.
  MemoryPool *pool = (MemoryPool *)memory_malloc(sizeof(MemoryPool));
  if (pool == NULL) {
    fprintf(stderr, "Memory pool creation failed\n");
    return NULL;
  }

  // Allocate the contiguous block of memory for the chunks.
  pool->memory = (uint8_t *)memory_malloc(chunk_size * capacity);
  if (pool->memory == NULL) {
    fprintf(stderr, "Memory pool creation failed\n");
    memory_free(pool);
    return NULL;
  }

  pool->chunk_size = chunk_size;
  pool->capacity = capacity;
  pool->free_chunks = NULL;

  // Initialize the free list by linking all chunks together.
  pool->free_chunks =
      _init_free_list((FreeNode *)pool->memory, chunk_size, capacity);

  return pool;
}

void memory_pool_destroy(MemoryPool *pool) {
  if (pool != NULL) {
    if (pool->memory != NULL) {
      memory_free(pool->memory);
    }
    memory_free(pool);
  }
}

void *memory_pool_alloc(MemoryPool *pool) {
  if (pool == NULL || pool->free_chunks == NULL) {
    return NULL;
  }

  FreeNode *node = pool->free_chunks;
  pool->free_chunks = node->next;

  return (void *)node;
}

bool memory_pool_free(MemoryPool *pool, void *ptr) {
  if (pool == NULL || ptr == NULL) {
    return false;
  }

  // Check if the pointer is within the pool's memory range.
  uint8_t *byte_ptr = (uint8_t *)ptr;
  if (byte_ptr < pool->memory ||
      byte_ptr >= pool->memory + (pool->capacity * pool->chunk_size)) {
    return false;
  }

  // Check if the pointer is aligned to the chunk size.
  if ((byte_ptr - pool->memory) % pool->chunk_size != 0) {
    return false;
  }

  // Add the pointer back to the free list.
  FreeNode *node = (FreeNode *)ptr;
  node->next = pool->free_chunks;
  pool->free_chunks = node;

  return true;
}

size_t memory_pool_free_count(const MemoryPool *pool) {
  if (pool == NULL) {
    return 0;
  }

  size_t count = 0;
  FreeNode *current = pool->free_chunks;
  while (current != NULL) {
    count++;
    current = current->next;
  }

  return count;
}

size_t memory_pool_capacity(const MemoryPool *pool) {
  if (pool == NULL) {
    return 0;
  }

  return pool->capacity;
}
