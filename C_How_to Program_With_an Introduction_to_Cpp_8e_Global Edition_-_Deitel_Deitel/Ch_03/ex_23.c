#include <stdio.h>

int main( void )
{
  int counter = 0, number, largest;

  while( counter < 10 ) {
    puts( "Enter a number:" );
    scanf( "%d", &number );

    if( number > largest ) {
      largest = number;
    }
    counter++;
  }
  printf( "The largest number in the set is %d\n", largest );
}
