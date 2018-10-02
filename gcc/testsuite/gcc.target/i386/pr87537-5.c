/* { dg-do compile } */
/* { dg-options "-mavx512f -O2 -mtune=skylake" } */
/* { dg-final { scan-assembler-times "vbroadcastsd\[ \\t\]+\[^\{\n\]*%zmm\[0-9\]" 1 } } */
/* { dg-final { scan-assembler-not "vmovsd" } } */

#include <immintrin.h>

__m512d
foo (void)
{
  return _mm512_set1_pd (2.0f);
}
