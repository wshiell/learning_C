#include <stdio.h>
#include <math.h>

int rounding(float number);

int main(void)
{
  float number;

  puts("Enter a decimal number (type -1 to quit):");
  scanf("%f", &number);

  printf("\n%s\t%s\n\n", "Number", "Rounded Number");
  
  while (number != -1) {
    printf("%f\t%d\n\n", number, rounding(number));

    puts("Enter a decimal number (type -1 to quit):");
    scanf("%f", &number);
  }
  puts("");
}

int rounding(float number)
{
  int roundedNumber;
  return roundedNumber = floor(number + .5);
}
