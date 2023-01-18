#include <stdio.h>
#include <math.h>

int main(void)
{
  unsigned int principal = 100000;
  double rate = .05;

  printf("%4s%21s\n", "Year", "Amount on Deposit");

  for (unsigned int year = 1; year <= 10; ++year) {

    unsigned int amount = principal * pow(1.0 + rate, year);

    unsigned int dollars = amount / 100;
    unsigned int cents = amount % 100;

    printf("%4u%14s%u.%u", year, "$ ",  dollars, cents);

    if (cents < 10) {
      unsigned int zero = 0;
      printf("%u", zero);
    }
    else {
      printf("%s", "");
    }
    puts("");
  }
}
