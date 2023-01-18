#include <stdio.h>

int main(void)
{
  float celcius, fahrenheit;

  printf("%12s %12s\n", "Fahrenheit", "Celcius");  

  for ( unsigned int temp = 30; temp <= 50; temp++) {
    celcius = (float) temp;
    fahrenheit = ((float)9 / 5) * celcius + 32;
    printf("%12.2f %12.2f\n", celcius, fahrenheit);
    
  }
}
