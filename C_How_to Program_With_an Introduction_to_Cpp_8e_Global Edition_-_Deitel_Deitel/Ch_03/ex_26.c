#include <stdio.h>

int main( void )
{

  int counter = 0, number, ultimate = 0, penultimate = 0;

  while( counter < 10 ) {
    puts( "Enter a number:" );
    scanf( "%d", &number );

    if( number > ultimate ) {
      penultimate = ultimate;
      ultimate = number;
    }
    number++;
    counter++;
  }

  printf( "Largest number: %d\n", ultimate );
  printf( "Second largest number: %d\n", penultimate );
}
