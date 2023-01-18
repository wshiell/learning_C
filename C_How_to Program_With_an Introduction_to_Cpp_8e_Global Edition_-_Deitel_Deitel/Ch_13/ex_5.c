#include <stdio.h>

#define SUM(x, y) printf("%s%d\n", "The Sum of " #x " and " #y " is ", (x + y));

int main(void)
{
  int x = 10, y = 3;
  
  SUM(x, y);
}
