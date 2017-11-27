/* { dg-do compile } */
/* { dg-options "-O2 -mindirect-branch=thunk-extern -fno-pic" } */

typedef void (*dispatch_t)(long offset);

dispatch_t dispatch[256];

int
male_indirect_jump (long offset)
{
  dispatch[offset](offset);
  return 0;
}

/* { dg-final { scan-assembler "push(?:l|q)\[ \t\]*_?dispatch" { target { ! x32 } } } } */
/* { dg-final { scan-assembler "pushq\[ \t\]%rax" { target x32 } } } */
/* { dg-final { scan-assembler-times "jmp\[ \t\]*\.LIND" 1 } } */
/* { dg-final { scan-assembler-times "call\[ \t\]*\.LIND" 1 } } */
/* { dg-final { scan-assembler "jmp\[ \t\]*__x86.indirect_thunk" } } */
/* { dg-final { scan-assembler-not {\t(lfence|pause)} } } */
