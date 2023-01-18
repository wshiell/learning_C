#include <stdio.h>

int main( void )
{

  int digit_1 = 0, digit_2 = 0, digit_3 = 0, armstrong, number;
  int digit_1_cubed, digit_2_cubed, digit_3_cubed, pause;

  while( digit_1 < 9) {
    while( digit_2 < 9 ) {
      while( digit_3 < 9 ) {

	digit_1_cubed = digit_1 * digit_1 * digit_1;
        digit_2_cubed = digit_2 * digit_2 * digit_2;
        digit_3_cubed = digit_3 * digit_3 * digit_3;
        armstrong = digit_1_cubed + digit_2_cubed + digit_3_cubed;
	number = 100 * digit_1 + 10 * digit_2 + digit_3;

	if( armstrong == number ) {
	  if( armstrong > 100 ) {
            printf( "%d\n", armstrong );
	  }
	}
	digit_3++;
      }
      digit_3 = 0;
      digit_2++;
    }
    digit_2 = 0;
    digit_1++;
  }
}
