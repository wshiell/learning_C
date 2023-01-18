#include <stdio.h>
#include <math.h>

void printDigits(int integer1, int integer2);

int main(void)
{
  int number1, number2;

  puts("Enter a five digit integer between 0 and 32767:");
  puts("(-1 to quit)");
  scanf("%d", &number1);

  while (number1 < -1 || number1 > 32767) {
    puts("Invalid number. Please re-enter.");
    scanf("%d", &number1);
    puts("Enter the divisor:");
    scanf("%d", &number2);
  }

  while (number1 != -1) {
    printDigits(number1, number2);
    puts("");

    puts("Enter a five digit integer between 0 and 32767:");
    puts("(-1 to quit)");
    scanf("%d", &number1);

    while (number1 < -1 || number1 > 32767) {
      puts("Invalid number. Please re-enter.");
      scanf("%d", &number1);
    }
    
  }
}

void printDigits(int integer1, int integer2)
{
  int integerQuotient, integerRemainder;
  
  integerQuotient = integer1 / integer2;
  integerRemainder = integer1 % integer2;

  integer1 = integerQuotient;
  integer2 = integer2;
  
  if (integerQuotient != 0)  {
    printDigits(integer1, integer2);
    printf( "%d ", integerRemainder);
  }
  else {
    printf( "%d ", integerRemainder);
  }
}
