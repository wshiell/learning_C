#include <stdio.h>

int main ( void )
{
  
  int sum, x;
  
  x = 1;
  sum = 0;

  while ( x < 11 ) {
    sum += x;
    x += 1;
  }

  printf( "The sum is: %d\n", sum );

}
