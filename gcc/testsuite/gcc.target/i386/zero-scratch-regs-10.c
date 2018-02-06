/* { dg-do compile { target *-*-linux* } } */
/* { dg-options "-O2 -mzero-caller-saved-regs=skip" } */

extern int foo (int) __attribute__ ((zero_caller_saved_regs("all")));

int
foo (int x)
{
  return x;
}

/* { dg-final { scan-assembler "xorl\[ \t\]*%edx, %edx" } } */
/* { dg-final { scan-assembler "movl\[ \t\]*%edx, %ecx" } } */
/* { dg-final { scan-assembler "movl\[ \t\]*%edx, %esi" { target { ! ia32 } } } } */
/* { dg-final { scan-assembler "movl\[ \t\]*%edx, %edi" { target { ! ia32 } } } } */
/* { dg-final { scan-assembler "movl\[ \t\]*%edx, %r8d" { target { ! ia32 } } } } */
/* { dg-final { scan-assembler "movl\[ \t\]*%edx, %r9d" { target { ! ia32 } } } } */
/* { dg-final { scan-assembler "movl\[ \t\]*%edx, %r10d" { target { ! ia32 } } } } */
/* { dg-final { scan-assembler "movl\[ \t\]*%edx, %r11d" { target { ! ia32 } } } } */
