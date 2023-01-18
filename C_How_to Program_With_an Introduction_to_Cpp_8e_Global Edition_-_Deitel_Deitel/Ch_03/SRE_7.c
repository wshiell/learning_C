#include <stdio.h>

int main ( void )
{

  unsigned x, y;
  unsigned i = 1, power = 1;

  puts("Enter x and y: " );
  scanf( "%u %u", &x, &y );

  while ( i <= y ) {
    power *= x;
    i++;
    printf( "%u\n", power );
  }
}
