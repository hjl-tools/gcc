/* { dg-do compile } */
/* { dg-options "-mavx512f -O2 -mtune=skylake" } */
/* { dg-final { scan-assembler-times "vbroadcastss\[ \\t\]+\[^\{\n\]*%zmm\[0-9\]" 1 } } */
/* { dg-final { scan-assembler-not "vmovss" } } */

#include <immintrin.h>

__m512
foo (float *x)
{
  return _mm512_broadcastss_ps (_mm_load_ss(x));
}
