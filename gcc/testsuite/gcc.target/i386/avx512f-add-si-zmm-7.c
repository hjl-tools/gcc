/* { dg-do compile } */
/* { dg-options "-mavx512f -O2" } */
/* { dg-final { scan-assembler-times "vpaddd\[ \\t\]+\[^\n\]*\\\{1to\[1-8\]+\\\}, %zmm\[0-9\]+, %zmm0" 1 } } */

#define type __m512i
#define vec 512
#define op add
#define op_suffix epi32
#define dup_suffix epi32
#define SCALAR int

#include "avx512-binop-7.h"
