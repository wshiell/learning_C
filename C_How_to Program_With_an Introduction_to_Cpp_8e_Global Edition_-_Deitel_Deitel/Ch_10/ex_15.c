#include <stdio.h>
#include <limits.h>

void displayBits(unsigned int value);

int main(void)
{
  unsigned int a;

  puts("Enter an integer:");
  scanf("%u", &a);
  
  displayBits(a);
}
void displayBits(unsigned int value)
{
  int SIZE = CHAR_BIT * sizeof(unsigned int);
  
  unsigned int mask = 1 << SIZE - 1;

  printf("%s%u\n", "Value: ", value);

  for (unsigned int i = 1; i <= SIZE; ++i) {

    putchar(value & mask ? '1' : '0');
    value <<= 1;

    if (i % 8 == 0) {
      putchar(' ');
    }
  }
  puts("");
}
