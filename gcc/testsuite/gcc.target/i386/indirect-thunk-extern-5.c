/* { dg-do compile { target *-*-linux* } } */
/* { dg-options "-O2 -mfunction-return=keep -fpic -fno-plt -mindirect-branch=thunk-extern" } */

extern void bar (void);

void
foo (void)
{
  bar ();
}

/* { dg-final { scan-assembler "push(?:l|q)\[ \t\]*bar@GOT" } } */
/* { dg-final { scan-assembler "jmp\[ \t\]*__x86.indirect_thunk" } } */
/* { dg-final { scan-assembler-not {\t(lfence|pause)} } } */
/* { dg-final { scan-assembler-not "jmp\[ \t\]*\.LIND" } } */
/* { dg-final { scan-assembler-not "call\[ \t\]*\.LIND" } } */
