#include <stdio.h>
#include <math.h>

int main(void)
{
  int limit = 100, exponent, counter = 0;
  float b = 1, number, base, exponential;
  
  printf("%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s", "a", "b", "sqrt(a)", "cbrt(a)", "exp(a)", "log(a)", "log10(a)", "fabs(a)", "ceil(a)");
  puts("\n");

  for (int count = 1; count <= limit; count++) {
    number = (float) count + .5;

    exponential = exp(number);
    
    while ((int) exponential / 10 > 0) {
      exponential /= 10;
      counter++;
    }

    base = exponential;
    exponent = counter;

    printf("%-15.2f%-15.0f%-15.2f%-15.2f", number, b, sqrt(number), cbrt(number));

    if (number < 21) {
      printf("%-3.2f%-6s%-5d", base, " x 10^", exponent);
    }
    else {
      printf("%-15d", 0);
    }
    
    printf("%-15.2f%-15.2f%-15.2f%-15.0f", log(number), log10(number), fabs(number), ceil(number));
    puts("");
  }

  printf("\n%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s", "a", "b", "floor(a)", "pow(a, b)", "fmod(a, b)", "sin(a)", "cos(a)", "tan(a)");
  puts("\n");

  for (int count = 1; count <= limit; count++) {
    number = (float) count + .5;    
    printf("%-15.2f%-15.0f%-15.0f%-15.2f%-15.2f%-15.2f%-15.2f%-15.2f", number, b, floor(number), pow(number, b), fmod(number, b), sin(number),
	   cos(number), tan(number));
    puts("");
  }
}
