/* { dg-do compile { target *-*-linux* } } */
/* { dg-options "-O2 -fpic -fno-plt -mindirect-branch=thunk-inline" } */

extern void bar (void);

int
foo (void)
{
  bar ();
  return 0;
}

/* { dg-final { scan-assembler "push(?:l|q)\[ \t\]*bar@GOT" } } */
/* { dg-final { scan-assembler-times "jmp\[ \t\]*\.LIND" 2 } } */
/* { dg-final { scan-assembler-times "call\[ \t\]*\.LIND" 2 } } */
/* { dg-final { scan-assembler-not "__x86.indirect_thunk" } } */
