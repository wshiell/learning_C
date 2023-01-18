#include <stdio.h>

int lcm(int number1, int number2);

int main(void)
{
  int number1, number2, lcMult;

  puts("Enter two integers:");
  scanf("%d%df", &number1, &number2);

  lcMult = lcm(number1, number2);
    
    printf("The lowest common multiple of %d and %d is: %d\n",
	   number1, number2, lcMult);
    puts("");
}

int lcm(int number1, int number2)
{
  int lcm;
  if (number1 == number2) {
    lcm = number1;
  }
  else {
    return lcm = number1 * number2;
  }
}
