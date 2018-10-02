/* { dg-do compile } */
/* { dg-options "-mavx512f -O2 -mtune=skylake" } */
/* { dg-final { scan-assembler-times "vbroadcastss\[ \\t\]+\[^\{\n\]*%zmm\[0-9\]" 1 } } */
/* { dg-final { scan-assembler-not "vmovss" } } */

#include <immintrin.h>

__m512
foo (void)
{
  return _mm512_set1_ps (2.0f);
}
