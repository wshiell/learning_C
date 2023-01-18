#include <stdio.h>

int main(void)
{
  float a;
  
  printf("\n%s\n\n%s", "Enter a floating point number:", "> ");
  scanf("%e", &a);
  printf("%s%f\n", "The value of the integer is: ", a);

  printf("\n%s\n\n%s", "Enter a floating point number:", "> ");
  scanf("%f", &a);
  printf("%s%f\n", "The value of the integer is: ", a);

  printf("\n%s\n\n%s", "Enter a floating point number:", "> ");
  scanf("%g", &a);
  printf("%s%f\n", "The value of the integer is: ", a);
}
