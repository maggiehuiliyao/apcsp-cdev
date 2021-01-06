#include<stdio.h>

int main()
{
  int a = 545;

  // print value and size of an int variable
  printf("int a value: %d and size: %lu bytes\n", a, sizeof(a));

  char b = 'b';
  printf("char b value: %c and size: %lu bytes\n", b, sizeof(b));

  float c = 123.456;
  printf("float c value: %.3f and size: %lu bytes\n", c, sizeof(c));

  double d = 123.456789;
  printf("double d value: %f and size: %lu bytes\n", d, sizeof(d));

  unsigned int e = 2345;
  printf("unsigned int e value: %d and size: %lu bytes\n", e, sizeof(e));

  short int f = 1234;
  printf("short int f value: %d and size: %lu bytes\n", f, sizeof(f));
}

