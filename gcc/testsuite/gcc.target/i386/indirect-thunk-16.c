/* { dg-do compile { target { *-*-linux* && { ! ia32 } } } } */
/* { dg-require-effective-target thunk_gotpcrelx_reloc } */
/* { dg-options "-O2 -mno-indirect-branch-register -mfunction-return=keep -fno-pic -fno-plt -mindirect-branch=thunk" } */

extern void bar (void);

void
foo (void)
{
  bar ();
}

/* { dg-final { scan-assembler "movq\[ \t\]*bar@GOTPCREL_THUNK" } } */
/* { dg-final { scan-assembler "jmp\[ \t\]*__x86_indirect_thunk_r" } } */
/* { dg-final { scan-assembler "jmp\[ \t\]*\.LIND" } } */
/* { dg-final { scan-assembler "call\[ \t\]*\.LIND" } } */
/* { dg-final { scan-assembler {\tpause} } } */
/* { dg-final { scan-assembler {\tlfence} } } */
