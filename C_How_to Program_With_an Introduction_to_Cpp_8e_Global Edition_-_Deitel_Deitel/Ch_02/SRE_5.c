#include <stdio.h>

int main ( void )
{

   //This program will calculate the product of three integers.
   printf( "%s", "Enter three integers: " );
   int x, y, z;
   scanf( "%d %d %d", &x, &y, &z );
   int result;
      result = x * y * z;
   printf( "The product is %d\n", result );


}
