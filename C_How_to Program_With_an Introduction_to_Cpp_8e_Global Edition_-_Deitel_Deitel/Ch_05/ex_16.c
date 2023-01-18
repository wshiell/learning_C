#include <stdio.h>
#include <math.h>

void validTriangle(double side1, double side2, double side3);
void triangleArea(double side1, double side2, double side3);

int main(void)
{
  double side1, side2, side3;
  
  printf("Enter three numbers, representing the sides of a triangle:");
  scanf("%lf%lf%lf", &side1, &side2, &side3);

  validTriangle(side1, side2, side3);
}

void validTriangle(double side1, double side2, double side3)
{
  
  if (side1 <= side2 + side3) {

    if (side2 <= side1 +side3) {

      if (side3 <= side1 + side2) {
	puts("The numbers represent the sides of a valid triangle");
        triangleArea(side1, side2, side3);
	
      }
      else {
        puts("The numbers do not represent the side of a valid triangle");
      }
    }
    else {
      puts("The numbers do not represent the side of a valid triangle");      
    }
  }
  else {
    puts("The numbers do not represent the side of a valid triangle");
  }
}

void triangleArea(double side1, double side2, double side3)
{
  double s = (side1 + side2 + side3) / 2;
  double area = sqrt(s * (s - side1) * (s - side2) * (s - side3));

  printf("Area of triangle with side %.2lf, %.2lf and %.2lf is: %lf\n",
	 side1, side2, side3, area);
}
  
