/* { dg-do compile { target *-*-linux* } } */
/* { dg-options "-O2 -mzero-caller-saved-regs=skip" } */

extern void foo (void) __attribute__ ((zero_caller_saved_regs("used")));

void
foo (void)
{
}

/* { dg-final { scan-assembler-not "xorl\[ \t\]*%" } } */
/* { dg-final { scan-assembler-not "movl\[ \t\]*%" } } */
