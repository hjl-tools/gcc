/* { dg-do compile } */
/* { dg-options "-mavx512vl -O2" } */
/* { dg-final { scan-assembler-times "vaddps\[ \\t\]+\[^\n\]*\\\{1to\[1-8\]+\\\}, %xmm\[0-9\]+, %xmm0" 1 } } */
/* { dg-final { scan-assembler-times "long\[ \\t\]+1074161254" 1 } } */

#define type __m128
#define vec
#define op add
#define op_suffix ps
#define dup_suffix ps
#define SCALAR float

#include "avx512-binop-7.h"
