#include <stdio.h>

float maximum(float number1, float number2, float number3, float number4);

int main(void)
{
  float number1, number2, number3, number4;

  printf("%s", "Enter a floating point number (1):\n");
  scanf("%f", &number1);

  printf("%s", "Enter a floating point number (2):\n");
  scanf("%f", &number2);

  printf("%s", "Enter a floating point number (3):\n");
  scanf("%f", &number3);

  printf("%s", "Enter a floating point number (4):\n");
  scanf("%f", &number4);

  maximum(number1, number2, number3, number4);
}

float maximum(float number1, float number2, float number3, float number4)
{
  float max;

  max = number1;

  if (number2 > max) {
    max = number2;
  }
  
  if (number3 > max) {
    max = number3; 
  }
  
  if (number4 > max) {
    max = number4;
  }

  printf("The largest number is: %f\n", max);
}
