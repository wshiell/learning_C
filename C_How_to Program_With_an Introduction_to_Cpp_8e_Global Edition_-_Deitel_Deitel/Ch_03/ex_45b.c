#include <stdio.h>

int main( void )
{

  int i = 0, n, n_factorial = 1;
  float e = 1, reciprocal;

  puts( "Enter a value of n, which will be use to formulate an" );
  puts( "approximation for e:" );
  scanf( "%d", &n );
  i = n - 1;
  
  if( n == 0 ) {
    n_factorial = 1;
  }
  else {
    while( i >= 0 ) {
      n_factorial = n_factorial * ( n - i );
      reciprocal = ( float ) 1 / n_factorial;
      e = e + reciprocal;
      i--;
    }
  }
  printf( "The value of e, using n = %d, is: %f\n", n, e );
}
