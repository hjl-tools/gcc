/* { dg-do compile { target *-*-linux* } } */
/* { dg-options "-O2 -mzero-caller-saved-regs=all" } */

void
foo (void)
{
}

/* { dg-final { scan-assembler "xorl\[ \t\]*%eax, %eax" } } */
/* { dg-final { scan-assembler "movl\[ \t\]*%eax, %edx" } } */
/* { dg-final { scan-assembler "movl\[ \t\]*%eax, %ecx" } } */
/* { dg-final { scan-assembler "movl\[ \t\]*%eax, %esi" { target { ! ia32 } } } } */
/* { dg-final { scan-assembler "movl\[ \t\]*%eax, %edi" { target { ! ia32 } } } } */
/* { dg-final { scan-assembler "movl\[ \t\]*%eax, %r8d" { target { ! ia32 } } } } */
/* { dg-final { scan-assembler "movl\[ \t\]*%eax, %r9d" { target { ! ia32 } } } } */
/* { dg-final { scan-assembler "movl\[ \t\]*%eax, %r10d" { target { ! ia32 } } } } */
/* { dg-final { scan-assembler "movl\[ \t\]*%eax, %r11d" { target { ! ia32 } } } } */
