#include <stdio.h>

int main ( void )
{

  int num;

  puts( "Enter a number to determine if it is odd or even: " );
  scanf( "%d", &num );

  if ( num % 2 == 0 ) {
    printf( "%d is an even number.\n", num );
  }
  if ( num % 2 != 0 ) {
    printf( "%d is an odd number.\n", num );
  }
}
