#include <stdio.h>

int main ( void )
{

  int height, weight, BMI;
  
  puts( "Enter your height (in meters): " );
  scanf( "%d", &height );

  puts( "Enter your weight (in kilograms): " );
  scanf( "%d", &weight );

  BMI = weight / ( height * height );

  printf( "Your BMI is: \n%d\n", BMI );

  puts( "BMI VALUES" );
  puts( "Underweight:\tless than 18.5" );
  puts( "Normal:\t\tbetween 18.5 and 24.9" );
  puts( "Overweight:\tbetween 25 and 29.9" );
  puts( "Obese:\t\t30 or greater" );

}
