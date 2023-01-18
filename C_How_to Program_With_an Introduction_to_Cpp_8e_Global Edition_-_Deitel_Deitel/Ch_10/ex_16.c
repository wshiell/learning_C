#include <stdio.h>

unsigned int multiple(unsigned int num);

unsigned int main(void)
{
  unsigned int y;

  puts("Enter an integer between 1 and 32000: ");
  scanf("%d", &y);

  if (multiple(y)) {
    printf("%d is a multiple of X\n", y);
  }
  else {
    printf("%d is NOT a multiple of X\n", y);
  }
}

unsigned int multiple(unsigned int num)
{
  unsigned int mask = 1;
  unsigned int mult = 1;

  for (unsigned int i = 1; i <= 10; i++, mask <<= 1) {

    if ((num & mask) != 0) {
      mult = 0;
      break;
    }
  }
  return mult;
}
