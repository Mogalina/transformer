#include "transformer/memory/allocator.h"
#include <stdio.h>
#include <stdlib.h>

void *memory_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  return ptr;
}

void *memory_calloc(size_t count, size_t size) {
  void *ptr = calloc(count, size);

  if (ptr == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  return ptr;
}

void *memory_realloc(void *ptr, size_t size) {
  void *new_ptr = realloc(ptr, size);

  if (new_ptr == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  return new_ptr;
}

void memory_free(void *ptr) {
  if (ptr != NULL) {
    free(ptr);
  }
}
