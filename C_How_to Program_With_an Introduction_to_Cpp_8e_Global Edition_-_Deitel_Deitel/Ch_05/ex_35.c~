#include <stdio.h>

int power(int base, int exponent);

int main(void)
{
  int number1, number2;
  
  puts("Enter two integers:");
  scanf("%d%d", &number1, &number2);

  int result;

  result = power(number1, number2);

  printf("%d raised to the %dth power = %d\n", number1, number2, result);
}

int power(int base, int exponent)
{
  int result;
  
  if (exponent == 1) {
    result = base;
    return result;
  }
  else {

    if (exponent == 0) {
      result = 1;
      return result;
    }
    else {
      int exp = exponent - 1;
      result = base * power(base, exp);
      return result;
    }
  }
}
