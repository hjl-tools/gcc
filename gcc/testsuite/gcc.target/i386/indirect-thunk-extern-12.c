/* { dg-do compile { target *-*-linux* } } */
/* { dg-options "-O2 -mno-indirect-branch-register -mfunction-return=keep -fno-pic -fno-plt -mindirect-branch=thunk-extern" } */

extern void bar (void);

int
foo (void)
{
  bar ();
  return 0;
}

/* { dg-final { scan-assembler "movl\[ \t\]*bar@GOT" { target ia32 } } } */
/* { dg-final { scan-assembler "call\[ \t\]*__x86_indirect_thunk_e" { target ia32 } } } */
/* { dg-final { scan-assembler "mov(l|q)\[ \t\]*bar@GOTPCREL" { target { ! ia32 } } } } */
/* { dg-final { scan-assembler "call\[ \t\]*__x86_indirect_thunk_r" { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-not "jmp\[ \t\]*\.LIND" } } */
/* { dg-final { scan-assembler-not "call\[ \t\]*\.LIND" } } */
/* { dg-final { scan-assembler-not {\t(lfence|pause)} } } */
