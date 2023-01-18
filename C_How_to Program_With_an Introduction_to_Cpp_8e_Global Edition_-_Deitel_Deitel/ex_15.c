#include <stdio.h>
#include <math.h>

int main(void)
{
  double principal = 1000.0;

  printf("%4s%21s\n", "Year", "Amount on Deposit");
  
  for (unsigned int rate = 5; rate <= 10; rate++) {
    printf("Interest rate: %u\%%\n", rate);
    
    for (unsigned int year = 1; year <= 10; ++year) {
      double interestRate = (float) rate / 100;
      double amount = principal * pow(1.0 + interestRate, year);

      printf("%4u%21.2f\n", year, amount);
    }
  }
}
