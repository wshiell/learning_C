#include <stdio.h>

union floatingPoint {
  float f;
  double d;
  long double x;
};
  
int main(void)
{
  union floatingPoint data;
  
  printf("%s\n\n%s", "Enter a floating-point value: ", "> ");
  scanf("%f", &data.f);
  printf("\n%s\n%f\t%lf\t%Lf\n", "data.f:", data.f, data.f, data.f);
  
  printf("%s\n\n%s", "Enter a double value: ", "> ");
  scanf("%lf", &data.d);
  printf("\n%s\n%f\t%lf\t%Lf\n", "data.d:", data.d, data.d, data.d);  

  printf("%s\n\n%s", "Enter a long double value: ", "> ");
  scanf("%Lf", &data.x);
  printf("\n%s\n%f\t%lf\t%Lf\n", "data.x:", data.x, data.x, data.x);
}
