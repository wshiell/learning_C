#include <stdio.h>
#include <math.h>

int main(void)
{
  printf("x = %f\n", fabs(10.85));
  printf("x = %f\n", floor(10.85));
  printf("x = %f\n", fabs(-0.678));
  printf("x = %f\n", ceil(9.234));
  printf("x = %f\n", fabs(0.0));
  printf("x = %f\n", ceil(-34.87));
  printf("x = %f\n", ceil(-fabs(-12 - floor(-9.5))));
  
  
}
