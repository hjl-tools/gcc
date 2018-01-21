/* { dg-do compile { target { *-*-linux* && { ! x32 } } } } */
/* { dg-options "-O2 -mno-indirect-branch-register -mfunction-return=keep -mindirect-branch=thunk -fcheck-pointer-bounds -mmpx -fno-pic -fno-plt" } */

void bar (char *);
char buf[10];

void
foo (void)
{
  bar (buf);
}

/* { dg-final { scan-assembler "movl\[ \t\]*bar@GOT" { target ia32 } } } */
/* { dg-final { scan-assembler "bnd call\[ \t\]*__x86_indirect_thunk_bnd_e" { target ia32 } } } */
/* { dg-final { scan-assembler "movq\[ \t\]*bar@GOTPCREL" { target lp64 } } } */
/* { dg-final { scan-assembler "bnd jmp\[ \t\]*__x86_indirect_thunk_bnd_r" { target lp64 } } } */
/* { dg-final { scan-assembler "jmp\[ \t\]*\.LIND" } } */
/* { dg-final { scan-assembler "bnd call\[ \t\]*\.LIND" } } */
/* { dg-final { scan-assembler "bnd ret" } } */
/* { dg-final { scan-assembler {\tpause} } } */
/* { dg-final { scan-assembler {\tlfence} } } */
