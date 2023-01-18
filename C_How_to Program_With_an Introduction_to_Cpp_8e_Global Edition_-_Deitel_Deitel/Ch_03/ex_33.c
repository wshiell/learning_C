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
    printf( "*" );
    outer_counter++;
  }
  puts( "" );
  outer_counter = 0;

  while( outer_counter < ( number - 2 ) ) {
    printf( "*" );
    while( inner_counter < ( number - 2 ) ) {
      printf( " " );
      inner_counter++;
    }
    printf( "*" );
    puts( "" );
    inner_counter = 0;
    outer_counter++;
  }

  outer_counter = 0;

  while( outer_counter < number ) {
    printf( "*" );
    outer_counter++;
  }
  puts( "" );
}
