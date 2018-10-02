/* { dg-do compile } */
/* { dg-options "-mavx512vl -O2 -mtune=skylake" } */
/* { dg-final { scan-assembler-times "vbroadcastss\[ \\t\]+\[^\{\n\]*%ymm\[0-9\]" 1 } } */
/* { dg-final { scan-assembler-not "vmovss" } } */

#include <immintrin.h>

__m256
foo (void)
{
  return _mm256_set1_ps (2.0f);
}
