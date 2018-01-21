/* { dg-do compile { target *-*-linux* } } */
/* { dg-options "-O2 -mno-indirect-branch-register -mfunction-return=keep -fno-pic -fno-plt -mindirect-branch=thunk" } */

extern void bar (void);

int
foo (void)
{
  bar ();
  return 0;
}

/* { dg-final { scan-assembler "pushl\[ \t\]*bar@GOT" { target ia32 } } } */
/* { dg-final { scan-assembler "jmp\[ \t\]*__x86_indirect_thunk" { target ia32 } } } */
/* { dg-final { scan-assembler-times "jmp\[ \t\]*\.LIND" 2 { target ia32 } } } */
/* { dg-final { scan-assembler-times "call\[ \t\]*\.LIND" 2 { target ia32 } } } */
/* { dg-final { scan-assembler "movq\[ \t\]*bar@GOTPCREL" { target { ! ia32 } } } } */
/* { dg-final { scan-assembler "call\[ \t\]*__x86_indirect_thunk_r" { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-times "jmp\[ \t\]*\.LIND" 1 { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-times "call\[ \t\]*\.LIND" 1 { target { ! ia32 } } } } */
/* { dg-final { scan-assembler {\tpause} } } */
/* { dg-final { scan-assembler {\tlfence} } } */
