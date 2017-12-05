/* { dg-do compile } */
/* { dg-options "-O2 -mfunction-return=thunk -mindirect-branch=thunk -fno-pic" } */

extern void (*bar) (void);

int
foo (void)
{
  bar ();
  return 0;
}

/* { dg-final { scan-assembler "jmp\[ \t\]*__x86.return_thunk" } } */
/* { dg-final { scan-assembler-not "__x86.return_thunk:" } } */
/* { dg-final { scan-assembler "jmp\[ \t\]*\.LIND" } } */
/* { dg-final { scan-assembler "call\[ \t\]*\.LIND" } } */
/* { dg-final { scan-assembler "__x86.indirect_thunk:" } } */
/* { dg-final { scan-assembler-times {\tlfence} 1 { target { ! x32 } } } } */
/* { dg-final { scan-assembler "push(?:l|q)\[ \t\]*_?bar" { target { ! x32 } } } } */
/* { dg-final { scan-assembler "jmp\[ \t\]*__x86.indirect_thunk" { target { ! x32 } } } } */
/* { dg-final { scan-assembler-times {\tlfence} 2 { target { x32 } } } } */
/* { dg-final { scan-assembler "call\[ \t\]*__x86.indirect_thunk\.(r|e)ax" { target { x32 } } } } */
/* { dg-final { scan-assembler-not "pushq\[ \t\]%rax" { target x32 } } } */
