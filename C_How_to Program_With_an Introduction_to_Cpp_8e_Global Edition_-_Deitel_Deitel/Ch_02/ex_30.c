#include <stdio.h>

int main ( void )
{

  int num;
  int digit1, digit2, digit3, digit4, digit5;

  puts( "Enter a five digit integer: " );
  scanf( "%d", &num );

  digit1 = num / 10000;
  digit2 = num % 10000 / 1000;
  digit3 = num % 1000 / 100;
  digit4 = num % 100 / 10;
  digit5 = num % 10;

  puts( "The number can be broken apart to produce: " );
  printf( "%d %d %d %d %d\n", digit1, digit2, digit3, digit4, digit5 );

}
