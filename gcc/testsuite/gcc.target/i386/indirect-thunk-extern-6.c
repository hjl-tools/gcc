/* { dg-do compile { target *-*-linux* } } */
/* { dg-options "-O2 -mfunction-return=keep -fpic -fno-plt -mindirect-branch=thunk-extern" } */

extern void bar (void);

int
foo (void)
{
  bar ();
  return 0;
}

/* { dg-final { scan-assembler "push(?:l|q)\[ \t\]*bar@GOT" } } */
/* { dg-final { scan-assembler-times "jmp\[ \t\]*\.LIND" 1 } } */
/* { dg-final { scan-assembler-times "call\[ \t\]*\.LIND" 1 } } */
/* { dg-final { scan-assembler "jmp\[ \t\]*__x86.indirect_thunk" } } */
/* { dg-final { scan-assembler-not {\t(lfence|pause)} } } */
