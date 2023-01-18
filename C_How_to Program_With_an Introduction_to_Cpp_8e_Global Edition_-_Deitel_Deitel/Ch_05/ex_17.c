#include <stdio.h>
#include <math.h>

int triangleTest(float side1, float side2, float side3);

int main(void)
{
  float side1, side2, side3;
  
  puts("Enter 3 numbers:");
  scanf("%f%f%f", &side1, &side2, &side3);

  if (triangleTest(side1, side2, side3)) {
    printf("%.2f, %.2f and %.2f are sides of a right angled triangle\n",
	   side1, side2, side3);
  }
  else {
    printf("%.2f, %.2f and %.2f do not represent the side of a right angled"
           " triangle\n", side1, side2, side3);
  }
}

int triangleTest(float side1, float side2, float side3)
{
  if (pow(side1, 2) + pow(side2, 2) == pow(side3, 2)) {
    return 1;
  }
  if (pow(side1, 2) + pow(side3, 2) == pow(side2, 2)) {
    return 1;
  }
  if(pow(side3, 2) + pow(side2, 2) == pow(side1, 2)) {
    return 1;
  }
  else {
    return 0;
  }
}
