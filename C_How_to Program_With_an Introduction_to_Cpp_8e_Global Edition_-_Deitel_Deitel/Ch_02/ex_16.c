#include <stdio.h>

int main( void )
{

  int a, b;
  
  printf( "Enter two numbers: \n" );
  scanf( "%d %d", &a, &b );
  printf( "Sum is %d\nProduct is %d\nQuotient is %d\n", a + b, a * b, a / b );
  printf( "Difference is %d\n", b - a );

}
