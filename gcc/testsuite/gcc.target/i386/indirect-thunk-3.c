/* { dg-do compile } */
/* { dg-options "-O2 -mfunction-return=keep -mindirect-branch=thunk -fno-pic" } */

typedef void (*dispatch_t)(long offset);

dispatch_t dispatch;

int
male_indirect_jump (long offset)
{
  dispatch(offset);
  return 0;
}

/* { dg-final { scan-assembler "push(?:l|q)\[ \t\]*_?dispatch" { target { ! x32 } } } } */
/* { dg-final { scan-assembler "jmp\[ \t\]*__x86.indirect_thunk" { target { ! x32 } } } } */
/* { dg-final { scan-assembler "call\[ \t\]*__x86.indirect_thunk\.(r|e)ax" { target x32 } } } */
/* { dg-final { scan-assembler "jmp\[ \t\]*\.LIND" } } */
/* { dg-final { scan-assembler "call\[ \t\]*\.LIND" } } */
/* { dg-final { scan-assembler {\tlfence} } } */
