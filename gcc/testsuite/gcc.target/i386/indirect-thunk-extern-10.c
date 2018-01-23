/* { dg-do compile { target { *-*-linux* && { ! ia32 } } } } */
/* { dg-require-effective-target thunk_gotpcrelx_reloc } */
/* { dg-options "-O2 -mno-indirect-branch-register -mfunction-return=keep -fno-pic -fno-plt -mindirect-branch=thunk-extern" } */

extern void bar (void);

void
foo (void)
{
  bar ();
}

/* { dg-final { scan-assembler "movq\[ \t\]*bar@GOTPCREL_THUNK" } } */
/* { dg-final { scan-assembler "jmp\[ \t\]*__x86_indirect_thunk_r" } } */
/* { dg-final { scan-assembler-not {\t(lfence|pause)} } } */
/* { dg-final { scan-assembler-not "jmp\[ \t\]*\.LIND" } } */
/* { dg-final { scan-assembler-not "call\[ \t\]*\.LIND" } } */
