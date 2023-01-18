#include <stdio.h>

int main ( void )
{
  int tempNumber = 1, totalNumber, divisor = 1, numberOfDivisors = 0, largestRatio;
  float ratio, largest = 1;

  printf( "%s", "Enter a number: " );
  scanf( "%d", &totalNumber );
  puts( "" );

  printf( "Number:\tNumber of Divisors\tRatio\t\tPrime?\n" );
  while( tempNumber <= totalNumber ) {
    while( divisor <= tempNumber ) {
      if( tempNumber % divisor == 0 ) {
        numberOfDivisors++;
      }
      divisor++;
    }
    ratio = ( float )tempNumber / numberOfDivisors;
    if( ratio > largest ) {
      if( numberOfDivisors != 2 ) {
	largest = ratio;
        largestRatio = tempNumber;
      }
    }

    printf( "%d\t%d\t\t\t%f\t", divisor - 1, numberOfDivisors, ratio );
    if( numberOfDivisors == 2 && totalNumber != 1 ) {
      printf( "%d is prime\n", tempNumber );
    }
    else {
      puts( "" );
    }
    numberOfDivisors = 0;
    tempNumber++;
    divisor = 1;
  }
  printf( "Number with largest ratio of number:sum of divisors: %d\n", largestRatio );

}
