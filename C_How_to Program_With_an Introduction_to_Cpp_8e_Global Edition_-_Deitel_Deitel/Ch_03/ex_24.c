#include <stdio.h>

int main( void )
{

  int number = 1, square, cube, fourth, counter = 0;

  puts( "N\tN^2\tN^3\tN^4" );

  while( counter < 10 ) {
    square = number * number;
    cube = number * square;
    fourth = square * square;

    printf( "%d\t%d\t%d\t%d\n", number, square, cube, fourth );
    counter++;
    number++;
  }

}
