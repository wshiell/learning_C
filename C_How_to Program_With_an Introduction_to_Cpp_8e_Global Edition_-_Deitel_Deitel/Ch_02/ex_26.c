#include <stdio.h>

int main ( void )
{

  int a, b;

  puts( "Enter two integers: " );
  scanf( "%d %d", &a, &b );

  if ( a % b == 0 ) {
    printf( "%d is a multiple of %d.\n", a, b );
    printf( "%d is %d times %d.\n", a, ( a / b ), b );
  }
  if ( a % b != 0 ) {
    printf( "%d is NOT a multiple of %d.\n", a, b);
  }
}
