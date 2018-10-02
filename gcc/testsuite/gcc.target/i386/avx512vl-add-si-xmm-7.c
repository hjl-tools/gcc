/* { dg-do compile } */
/* { dg-options "-mavx512vl -O2" } */
/* { dg-final { scan-assembler-times "vpaddd\[ \\t\]+\[^\n\]*\\\{1to\[1-8\]+\\\}, %xmm\[0-9\]+, %xmm0" 1 } } */
/* { dg-final { scan-assembler-times "(?:long|quad)\[ \\t\]+2" 1 } } */

#define type __m128i
#define vec
#define op add
#define op_suffix epi32
#define dup_suffix epi32
#define SCALAR int

#include "avx512-binop-7.h"
