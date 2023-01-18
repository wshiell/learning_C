#include <stdio.h>

int main( void )
{

  float radius, circumference, diameter, area;
  float pi = 3.14159;
  
  puts( "Enter radius value:" );
  scanf( "%f", &radius );

  diameter = radius * 2;
  circumference = 2 * pi * radius;
  area = pi * radius * radius;

  printf( "Radius: %f\nDiameter: %f\n", radius, diameter );
  printf( "Circumference: %f\nArea: %f\n", circumference, area );
}
