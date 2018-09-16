/* { dg-do compile } */
/* { dg-options "-O2 -march=haswell" } */
/* { dg-final { scan-assembler-not "vmovq" } } */

#include <immintrin.h>

int
f (void *ptr)
{
  __m128i data = _mm_loadl_epi64((__m128i *)ptr);
  data = _mm_cvtepu8_epi16(data);
  return _mm_cvtsi128_si32(data);
}
