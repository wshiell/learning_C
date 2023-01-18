#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  srand(time(NULL));
  
  int i;
  int j;
  int k;
  double l;

  l = rand();
  
  puts("Enter things:");
  k = scanf("%d%d", &i, &j);
  printf("i^j = %f\n", pow(i, j));
  printf("k = %d\n", k);
  printf("l = %.2f\n", l);
}
