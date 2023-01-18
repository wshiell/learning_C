#include <stdio.h>

int main( void )
{

  int inner_counter = 0, outer_counter = 0, number;

  puts( "Enter value for length of side (between 1 and 20):" );
  scanf( "%d", &number );

  while( number > 20 ) {
    puts( "Invalid input" );
    puts( "Enter value for length of side:" );
    scanf( "%d", &number );
  }
  
  while( outer_counter < number ) {
    while( inner_counter < number ) {
      printf( "*" );
      inner_counter++;
    }
    puts( "" );
    inner_counter = 0;
    outer_counter++;
  }
}
