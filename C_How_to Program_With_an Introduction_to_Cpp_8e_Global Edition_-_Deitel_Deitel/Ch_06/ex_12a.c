#include <stdio.h>

int main(void)
{
  double sales[20];

  for (int count = 0; count < 20; count++) {
    puts("Enter first sales figure:");
    scanf("%lf", &sales[count]);
  }

  for (int count = 0; count < 20; count++) {
    printf("%.3lf ", sales[count]);
  }

  puts("");
}
