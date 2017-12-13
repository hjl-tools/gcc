/* { dg-do compile } */
/* { dg-options "-O2 -mindirect-branch=thunk -fno-pic" } */

void func0 (void);
void func1 (void);
void func2 (void);
void func3 (void);
void func4 (void);
void func4 (void);
void func5 (void);

void
bar (int i)
{
  switch (i)
    {
    default:
      func0 ();
      break;
    case 1:
      func1 ();
      break;
    case 2:
      func2 ();
      break;
    case 3:
      func3 ();
      break;
    case 4:
      func4 ();
      break;
    case 5:
      func5 ();
      break;
    }
}

/* { dg-final { scan-assembler "push(?:l|q)\[ \t\]*\.L\[0-9\]+\\(,%" { target { ! x32 } } } } */
/* { dg-final { scan-assembler "jmp\[ \t\]*__x86.indirect_thunk" { target { ! x32 } } } } */
/* { dg-final { scan-assembler "jmp\[ \t\]*__x86.indirect_thunk\.(r|e)ax" { target x32 } } } */
/* { dg-final { scan-assembler "jmp\[ \t\]*\.LIND" } } */
/* { dg-final { scan-assembler "call\[ \t\]*\.LIND" } } */
/* { dg-final { scan-assembler {\tlfence} } } */
