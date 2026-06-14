/* The MIT License

   Copyright (c) 2026, by menshikow <adreydmenshikov@gmail.com>

   Permission is hereby granted, free of charge, to any person obtaining
   a copy of this software and associated documentation files (the
   "Software"), to deal in the Software without restriction, including
   without limitation the rights to use, copy, modify, merge, publish,
   distribute, sublicense, and/or sell copies of the Software, and to
   permit persons to whom the Software is furnished to do so, subject to
   the following conditions:

   The above copyright notice and this permission notice shall be
   included in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.
*/

#ifndef TSTL_VECTOR_H
#define TSTL_VECTOR_H

#include <cstddef>
#include <stdlib.h>

// TODO what to do with normal ints?
#define tstl_roundup(x)                                                        \
  _Generic((x),                                                                \
      uint32_t: tstl_roundup32(x),                                             \
      uint64_t: tstl_roundup64(x),                                             \
      unsigned long: tstl_roundup64(x))

static inline uint64_t tstl_roundup64(uint64_t x) {
  x--;
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;
  x |= x >> 32;
  return ++x;
}

static inline uint32_t tstl_roundup64(uint32_t x) {
  x--;
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  return ++x;
}

#define TSTL_VEC(T)                                                            \
  typedef struct {                                                             \
    T *data;                                                                   \
    size_t size;                                                               \
    size_t capacity;                                                           \
  } Vec_##T;                                                                   \
                                                                               \
  static inline void vec

#define

#endif /* TSTL_VECTOR_H */
