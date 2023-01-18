#include <stdio.h>

int main ( void )
{

  float principal, rate, interest;
  int days;

  puts( "Enter loan principal (-1 to end):" );
  scanf( "%f", &principal );

  while ( principal != -1 ) {
    puts( "Enter interest rate:" );
    scanf( "%f", &rate );

    puts( "Enter term of the loan in days:" );
    scanf( "%d", &days );
    
    interest = principal * rate * days / 365;

    printf( "The interest charge is $%.2f\n", interest );

    puts( "Enter loan principal (-1 to end):" );
    scanf( "%f", &principal );
  }
}
