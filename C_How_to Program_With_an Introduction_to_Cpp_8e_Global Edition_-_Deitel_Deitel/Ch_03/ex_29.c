#include <stdio.h>

int main( void )
{
  int outer_count = 1;
  while( outer_count <= 10 ) {
    int inner_count = 1;
    while( inner_count <= outer_count ) {
      printf( "*" );
      inner_count++;
    }
    printf( "\n" );
    outer_count++;
  }
}
