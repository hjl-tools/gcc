/* { dg-do compile } */
/* { dg-options "-mavx512f -O2 -mtune=skylake" } */
/* { dg-final { scan-assembler-times "vbroadcastsd\[ \\t\]+\[^\{\n\]*%zmm\[0-9\]" 1 } } */
/* { dg-final { scan-assembler-not "vmovsd" } } */

#include <immintrin.h>

__m512d
foo (double *x)
{
  return _mm512_broadcastsd_pd (_mm_load_sd(x));
}
