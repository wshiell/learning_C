#include <stdio.h>

int gcd(int x, int y);

int main(void)
{
  int gCD, hold, x, y;

  puts("Enter two integers:");
  scanf("%d%d", &x, &y);
  
  if (x > y) {
    x = x;
  }

  if (x < y) {
    hold = y;
    y = x;
    x = hold;
  }

  gCD = gcd(x, y);
  
  printf("The greatest common divisor of %d and %d is: %d\n", x, y, gCD);
}

int gcd(int x, int y)
{
  int gCD;
  
  printf("gcd(x,y) = gcd(%d,%d)\n", x, y);
  puts("")  ;
  
  if (y == 0) {
    gCD = x;
    return gCD;
  }
  else {
    gcd(y, x % y);
  }
}
