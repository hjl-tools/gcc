/* { dg-do compile { target *-*-linux* } } */
/* { dg-options "-O2 -mzero-caller-saved-regs=skip" } */

void
foo (void)
{
}

/* { dg-final { scan-assembler-not "xorl\[ \t\]*%" } } */
/* { dg-final { scan-assembler-not "movl\[ \t\]*%" } } */
