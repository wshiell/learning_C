#include <stdio.h>

int main( void )
{

  int i = 0, n, n_factorial = 1;

  puts( "Value of n:" );
  scanf( "%d", &n );

  if( n == 0 ) {
    n_factorial = 1;
  }
  else {
    while( i < n ) {
      n_factorial = n_factorial * ( n - i );
      i++;
    }
  }
  printf( "n! = %d\n", n_factorial );
}
