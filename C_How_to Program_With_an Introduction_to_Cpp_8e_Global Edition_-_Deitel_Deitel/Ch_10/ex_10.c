#include <stdio.h>

void displayBits(unsigned int a);

int main(void)
{
  unsigned int a;

  printf("\n%s\n\n%s", "Enter an integer:", "> ");
  scanf("%u", &a);
  
  printf("%s\n", "Integer 'a' before right shifting:");
  displayBits(a);
  
  printf("%s\n", "Integer 'a' before right shifting: ");
  displayBits(a >> 4);
}

void displayBits(unsigned int a)
{
  unsigned int mask = 1 << 31;

  printf("%s%u\n", "Value: ", a);
  
  for (unsigned int i = 1; i <= 32; ++i) {
    putchar(a & mask ? '1' : '0');
    a <<= 1;

    if (i % 8 == 0) {
      printf("%c", ' ');
    }
  }
  puts("");
}
