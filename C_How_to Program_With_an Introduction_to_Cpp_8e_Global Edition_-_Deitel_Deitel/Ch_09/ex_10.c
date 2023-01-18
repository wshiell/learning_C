#include <stdio.h>

int main(void)
{
  int fahrenheit = 212;
  double celsius;

  printf("\n%s\n\n", "*** Fahrenheit to Celcius Temperature Converter ***");

  printf("%10s%10s\n\n", "Fahrenheit", "Celsius");

  for (int temp = 1; temp <= fahrenheit; temp++) {

    celsius = 5.0 / 9.0 * (temp - 32);
  
    printf("%-10d%+-10.3f\n", temp, celsius);
  }
  
}
