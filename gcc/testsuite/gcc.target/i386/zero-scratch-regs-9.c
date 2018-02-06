/* { dg-do compile { target *-*-linux* } } */
/* { dg-options "-O2 -mzero-caller-saved-regs=skip" } */

extern int foo (int) __attribute__ ((zero_caller_saved_regs("used")));

int
foo (int x)
{
  return x;
}

/* { dg-final { scan-assembler-not "xorl\[ \t\]*%" { target ia32 } } } */
/* { dg-final { scan-assembler "xorl\[ \t\]*%edi, %edi" { target { ! ia32 } } } } */
