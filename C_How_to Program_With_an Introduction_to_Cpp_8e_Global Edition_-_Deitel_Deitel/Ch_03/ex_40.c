#include <stdio.h>

int main( void )
{

  int number = 0, numberCubed;

  while( number >= 0 ) {
    numberCubed = number * number * number;
    printf( "%d", numberCubed );
    number++;
  }
}
