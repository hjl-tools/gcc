/* { dg-do run } */
/* { dg-options "-O" } */
/* { dg-require-effective-target indirect_jumps } */

void *buf[6] = {
  (void *) -1,
  (void *) -1,
  (void *) -1,
  (void *) -1,
  (void *) -1,
  (void *) -1
};

void raise0(void)
{
  __builtin_longjmp (buf, 1);
}

int execute(int cmd)
{
  int last = 0;

  if (__builtin_setjmp (buf) == 0)
    while (1)
      {
        last = 1;
        raise0 ();
      }

  if (last == 0)
    return 0;
  else
    return cmd;
}

int main(void)
{
  if (execute (1) == 0)
    __builtin_abort ();

  if (buf[5] != (void *) -1)
    __builtin_abort ();

  return 0;
}
