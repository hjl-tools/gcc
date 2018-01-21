/* { dg-do compile { target *-*-linux* } } */
/* { dg-options "-O2 -mno-indirect-branch-register -mfunction-return=keep -fno-pic -fno-plt -mindirect-branch=thunk-inline" } */

extern void bar (void);

int
foo (void)
{
  bar ();
  return 0;
}

/* { dg-final { scan-assembler "pushl\[ \t\]*bar@GOT" { target ia32 } } } */
/* { dg-final { scan-assembler "movq\[ \t\]*bar@GOTPCREL" { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-times "jmp\[ \t\]*\.LIND" 2 } } */
/* { dg-final { scan-assembler-times "call\[ \t\]*\.LIND" 2 } } */
/* { dg-final { scan-assembler-times {\tpause} 1 } } */
/* { dg-final { scan-assembler-times {\tlfence} 1 } } */
/* { dg-final { scan-assembler-not "__x86_indirect_thunk" } } */
