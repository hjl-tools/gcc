/* { dg-do compile } */
/* { dg-options "-O2 -march=haswell" } */
/* { dg-final { scan-assembler-not "vmov(d|q)" } } */

#include <immintrin.h>

void
f (void *dst, void *ptr)
{
  __m128i data = _mm_loadl_epi64((__m128i *)ptr);
  data = _mm_cvtepi32_epi64(data);
  _mm_storeu_si128((__m128i*)dst, data);
}
