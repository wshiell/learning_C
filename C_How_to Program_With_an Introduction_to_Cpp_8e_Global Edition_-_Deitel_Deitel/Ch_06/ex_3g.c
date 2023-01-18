#include <stdio.h>
#define SIZE 10

int main(void)
{
  double array[SIZE] = {0};
 
  array[9] = 1.667;
  array[7] = 3.333;
  printf("%.2f %.2f\n", array[6], array[9]);

  for (int x = 0; x < SIZE; x++) {
    printf("%f\n", array[x]);
  }
  puts("");
}
