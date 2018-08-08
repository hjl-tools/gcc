// { dg-options "-O -g -fno-omit-frame-pointer -fno-var-tracking" }

struct Foo
{
  int bar(int a, int b, int c, int i1, int i2, int i3, int d);
};

int Foo::bar(int a, int b, int c, int i1, int i2, int i3, int d)
{
  return 0;
}
