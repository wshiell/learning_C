#include <stdio.h>
#include <stdarg.h>

int product(int i, ...);

int main(void)
{
  int a = 1;
  int b = 3;
  int c = 5;
  int d = 7;

  printf("%s%d\n%s%d\n%s%d\n%s%d\n", "a = ", a, "b = ", b, "c = ", c, "d = ", d);
  printf("The product of %d and %d is %d\n", a, b, product(2, a, b));
  printf("The product of %d, %d and %d is %d\n", a, b, c, product(3, a, b, c));
  printf("The product of %d, %d, %d and %d is %d\n", a, b, c, d, product(4, a, b, c, d));
}

int product(int i, ...)
{
  int product = 1;
  
  va_list ap;

  va_start(ap, i);

  for (int j = 0; j < i; j++) {
    product *= va_arg(ap, int);
  }

  va_end(ap);

  return product;
}
