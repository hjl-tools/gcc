/* { dg-do compile { target { *-*-linux* && lp64 } } } */
/* { dg-require-effective-target thunk_gotpcrelx_reloc } */
/* { dg-options "-O2 -mno-indirect-branch-register -mfunction-return=keep -mindirect-branch=thunk -fcheck-pointer-bounds -mmpx -fpic -fno-plt" } */

void bar (char *);
char buf[10];

void
foo (void)
{
  bar (buf);
}

/* { dg-final { scan-assembler "movq\[ \t\]*bar@GOTPCREL_THUNK" } } */
/* { dg-final { scan-assembler "bnd jmp\[ \t\]*__x86_indirect_thunk_bnd_r" } } */
/* { dg-final { scan-assembler "jmp\[ \t\]*\.LIND" } } */
/* { dg-final { scan-assembler "bnd call\[ \t\]*\.LIND" } } */
/* { dg-final { scan-assembler "bnd ret" } } */
/* { dg-final { scan-assembler {\tpause} } } */
/* { dg-final { scan-assembler {\tlfence} } } */
