#include <stdio.h>

int main ( void )
{

  int x = 1;
  int total = 0;
  while( x <= 5 ) {
    total += x * x;
    ++x;
  }
  printf( "Total is %d\n", total );
}
