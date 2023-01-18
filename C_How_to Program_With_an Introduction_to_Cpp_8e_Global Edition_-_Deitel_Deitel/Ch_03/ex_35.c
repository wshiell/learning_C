#include <stdio.h>

int main( void )
{

  int digit_1, digit_2, digit_3, digit_4, digit_5;
  int number, binaryNumber;

  puts( "Enter a binary number of up to 5 digits (eg. 11001):" );
  scanf( "%d", &binaryNumber );

  digit_1 = binaryNumber / 10000;
  digit_2 = ( binaryNumber % 10000 ) / 1000;
  digit_3 = ( binaryNumber % 1000 ) / 100;
  digit_4 = ( binaryNumber % 100 ) / 10;
  digit_5 = ( binaryNumber % 10 );

  number = 1 * digit_5 + 2 * digit_4 + 4 * digit_3 + 8 * digit_2 +
           16 * digit_1;

  printf( "%d in base 10 is: %d\n", binaryNumber, number );
}
