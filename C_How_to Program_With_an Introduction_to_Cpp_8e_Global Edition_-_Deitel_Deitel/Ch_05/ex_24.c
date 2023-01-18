#include <stdio.h>

float toYen(int dollar);
float toEuro(int dollar);

int main(void)
{
  printf("%-12s%12s%12s\n", "Dollars", "Euro", "Yen");

  for (int count = 1; count <= 36; count++) {
    printf("%s", "*");
  }
  puts("");
  
  for (int dollars = 10; dollars <= 100; dollars += 10) {
    printf("%-12d%12.2f%12.2f\n", dollars, toEuro(dollars), toYen(dollars));
  }
}

float toYen(int dollar)
{
  float yen = dollar * 118.87;
  return yen;
}

float toEuro(int dollar)
{
  float euro = dollar * 0.92;
  return euro;
}
