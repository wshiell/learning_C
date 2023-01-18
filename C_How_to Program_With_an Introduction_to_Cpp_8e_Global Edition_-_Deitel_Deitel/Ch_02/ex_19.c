#include <stdio.h>

int main ( void )
{

  int a, b, c; // integers to be input
  int smallest; // smallest integer
  int largest; // largest integer

  puts( "Enter three different integers: " );
  scanf( "%d%d%d", &a, &b, &c );
  
  int sum = a + b + c; //sum of the integers
  int product = a * b * c; // product of the integers
  float average = ( float ) ( a + b + c ) / 3; // average of the integers
  
  if ( a < b ) {
    if (a < c ) {
      smallest = a; // smallest integer is a
      if ( b < c ) {
	largest = c; // largest integer is c, smallest integer is a
      }
      if ( c < b ) {
	largest = b; // largest integer is b, smallest integer is a
      }
    }
  }
  if ( b < a ) {
    if ( b < c ) {
      smallest = b; // smallest integer is b
      if ( a < c ) {
	largest = c; // largest integer is c, smallest integer is b
      }
      if ( c < a ) {
	largest = a; // largest integer is a, smallest integer is b
      }
    }
  }
  if ( c < a ) {
    if ( c < b ) {
      smallest = c; // smallest integer is c
      if ( a < b ) {
	largest = b; // largest integer is b, smallest integer is c
      }
      if ( b < a )
        largest = a; // largest integer is a, smallest integer is c
    }
  }
  printf( "Average: %.2f\n", average );
  printf( "Product: %d\n", product );
  printf( "Smallest: %d\n", smallest );
  printf( "Largest: %d\n", largest );
  
}
