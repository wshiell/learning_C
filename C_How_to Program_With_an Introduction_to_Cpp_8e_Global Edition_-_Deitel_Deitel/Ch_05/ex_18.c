#include <stdio.h>

int isEven(int number);

int main(void)
{
  int number;
  puts("Enter a number to determine whether it is even or odd:");
  puts("(EOF to quit)");

  while ((number = getchar()) != EOF) {

    if (isEven(number)) {
      puts("Number is even.\n");
    }
    else {
      puts("Number is odd.\n");
    }
  }
}

int isEven( int number)
{
  if (number % 2 == 0) {
    return 1;
  }
  else {
    return 0;
  }
}
