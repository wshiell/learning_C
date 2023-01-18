#include <stdio.h>

int main(void)
{
  int sum = 0;

  for ( unsigned int counter = 1; counter <= 100; counter++) {
    sum += 7 * counter;
  }

  printf("Sum of all multiples of 7 from 1 to 100 is: %d\n", sum);
}
