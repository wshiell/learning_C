#include <stdio.h>

int main ( void )
{
  int accountNumber, mortgageAmount, mortgageTerm, totalInterest;
  int monthlyInterest, totalPayment;
  float interestRate;

  puts( "Enter account number (-1 to end):" );
  scanf( "%d", &accountNumber );

  while ( accountNumber != -1 ) {
    puts( "Enter mortgage amount (in dollars): " );
    scanf( "%d", &mortgageAmount );
    
    puts( "Enter mortgage term (in years):" );
    scanf( "%d", &mortgageTerm );
    
    puts( "Enter interest rate (as a decimal):" );
    scanf( "%f", &interestRate );

    totalInterest = mortgageAmount * mortgageTerm * interestRate;
    totalPayment = totalInterest + mortgageAmount;
    monthlyInterest = totalPayment / ( mortgageTerm * 12 );
    
    printf( "The monthly payable interest: $%d\n", monthlyInterest);

    puts( "Enter account number (-1 to end):" );
    scanf( "%d", &accountNumber );
  }
}
