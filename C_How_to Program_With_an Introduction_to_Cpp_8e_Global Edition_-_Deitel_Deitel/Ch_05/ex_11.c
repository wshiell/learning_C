#include <stdio.h>
#include <math.h>

int roundToInteger(float number);
float roundToTenths(float number);
float roundToHundredths(float number);
float roundToThousandths(float number);

int main(void)
{
  float number;

  puts("Enter a number with 4 digits after the decimal:");
  scanf("%f", &number);

  printf("Original Number: %.4f\n", number);
  printf("Number rounded to nearest integer: %d\n", roundToInteger(number));
  printf("Number rounded to nearest tenth: %.1f\n", roundToTenths(number));
  printf("Number rounded to the nearest hundredth: %.2f\n", roundToHundredths(number));
  printf("Number rounded to the nearest thousandth: %.3f\n", roundToThousandths(number));
}

int roundToInteger(float number)
{
  return floor(number + .5);
}

float roundToTenths(float number)
{
  return floor(number * 10 + .5) / 10;
}

float roundToHundredths(float number)
{
  return floor(number * 100 + .5) / 100;  
}

float roundToThousandths(float number)
{
  return floor(number * 1000 + .5) / 1000;  
}
