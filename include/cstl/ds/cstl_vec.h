#ifndef CSTL_VECTOR_H
#define CSTL_VECTOR_H

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum {
  SUCCESS,
  ERR_OUT_OF_MEMORY,
} Err;

// Logic Layer
static inline uint64_t cstl_roundup64(uint64_t x) {
  x--;
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;
  x |= x >> 32;
  return ++x;
}

static inline uint32_t cstl_roundup32(uint32_t x) {
  x--;
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;
  return ++x;
}

// Dispatcher Layer
#define cstl_roundup(x)                                                        \
  _Generic((x), uint32_t: cstl_roundup32, uint64_t: cstl_roundup64)(x)

// Generator Layer
#define CSTL_VEC(T)                                                            \
  typedef struct {                                                             \
    T *data;                                                                   \
    size_t size;                                                               \
    size_t cap;                                                                \
  } Vec_##T;                                                                   \
                                                                               \
  static inline void vec_##T##_push(Vec_##T *v, T val) {                       \
    if (v->size == v->cap) {                                                   \
      size_t new_cap = (v->cap == 0) ? 8 : v->cap * 2;                         \
      T *new_data = realloc(v->data, new_cap * sizeof(T));                     \
                                                                               \
      if (!new_data) {                                                         \
        return;                                                                \
      }                                                                        \
      v->data = new_data;                                                      \
      v->cap = new_cap;                                                        \
    }                                                                          \
    v->data[v->size++] = val;                                                  \
  }

#endif
