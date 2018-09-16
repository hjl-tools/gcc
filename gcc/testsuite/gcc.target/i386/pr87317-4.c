/* { dg-do compile } */
/* { dg-options "-O2 -march=haswell" } */
/* { dg-final { scan-assembler-not "vmov(d|q)" } } */

#include <immintrin.h>

void
f (void *dst, __m64 x)
{
  __m128i y = _mm_movpi64_epi64(x);
  __m128i z = _mm_cvtepu8_epi16(y);
  _mm_storeu_si128((__m128i*)dst, z);
}
