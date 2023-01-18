#include <stdio.h>

int main( void )
{
  int outer_count = 1, inner_count = 0;

  while( outer_count <= 8 ) {
    if(outer_count % 2 == 0 ) {
      printf( "%s", " " );
    }
    while( inner_count <= 8 ) {
      printf( "%s", "* " );
      inner_count++;
    }
    outer_count++;
    inner_count = 0;
    puts( "" );
  }
}
