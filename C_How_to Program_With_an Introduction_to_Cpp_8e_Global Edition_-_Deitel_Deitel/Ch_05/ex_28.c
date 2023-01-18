#include <stdio.h>

int sumDigits(int number);

int main(void)
{
  int number, sum;

  puts("Enter an integer:");
  scanf("%d", &number);

  printf("Sum of the digits of %d is: %d\n",
	 number, sum = sumDigits(number));
}

int sumDigits(int number)
{
  int sum = 0, remainder, quotient;

  remainder = number % 10;
  quotient = number / 10;

  if (quotient == 0 && remainder == 0) {
    return 0;
  }
  else {
    return sum = remainder + sumDigits(quotient);
  }
}

