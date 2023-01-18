#include <stdio.h>

void power2(int number, int pow);
void displayBits(int value);

int main(void)
{
  int number, pow;
  
  printf("%s\n\n%s", "Enter an integer", "> ");
  scanf("%d", &number);

  printf("%s\n\n%s", "Enter the power to which two is raised", "> ");
  scanf("%d", &pow);

  power2(number, pow);
}

void power2(int number, int pow)
{
  printf("\n%s\n", "number * 2^pow: ");
  displayBits(number << pow);
}

void displayBits(int value)
{
  unsigned int mask = 1 << 31;

  printf("\n%d: ", value);
  
  for (unsigned int i = 1; i <= 32; ++i) {

    putchar(value & mask ? '1' : '0');
    value <<= 1;

    if (i % 8 == 0) {
      printf("%c", ' ');
    }
  }
  puts("");
}
