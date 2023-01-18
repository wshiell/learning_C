#include <stdio.h>

int main( void )
{

  int i = 0, n, n_factorial = 1, x, x_power = 1;
  float e_x = 1, reciprocal;

    puts( "Enter a value of n, which will be use to formulate an" );
    puts( "approximation for e^x (-1 to quit):" );
    scanf( "%d", &n );

    while( n != -1 ) {
      puts( "\nEnter value of x:" );
      scanf( "%d", &x );
  
      i = n - 1;
  
      if( n == 0 ) {
        n_factorial = 1;
      }
      else {
        while( i >= 0 ) {
          n_factorial = n_factorial * ( n - i );
          x_power = x_power * x;
          reciprocal = ( float ) 1 / n_factorial;
          e_x  = e_x + x_power * reciprocal;
          i--;
        }
      }

      printf( "\nThe value of e^x, using n = %d, is: %f\n", n, e_x );

      i = n - 1;
      e_x = 1;
      x_power = 1;
      n_factorial = 1;
      
      puts( "\nEnter a value of n, which will be use to formulate an" );
      puts( "approximation for e^x (-1 to quit):" );
      scanf( "%d", &n );
    }
}
