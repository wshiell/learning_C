#include <stdio.h>

int main( void )
{

  int side = 10, outer_counter = 1, inner_counter = 1;

  //  puts( "Enter the size of Floyd's Triangle:" );
  //  scanf( "%d", &side );

  while( outer_counter <= side ) {
    while( inner_counter <= outer_counter ) {
      printf( "%d", outer_counter );
      inner_counter++;
    }
    puts( "" );
    inner_counter = 0;
    outer_counter++;
  }
}
