#include <stdio.h>

int main ( void )
{

  float weeklyPay = 200, totalEarnings;
  float commissionRate = .09, grossSales;

  puts( "Enter sales in dollars (-1 to end):" );
  scanf( "%f", &grossSales );

  while ( grossSales != -1 ) {
    totalEarnings = weeklyPay + commissionRate * grossSales;
    printf( "Salary is: $%.2f\n", totalEarnings );

   puts( "Enter sales in dollars (-1 to end):" );
   scanf( "%f", &grossSales );
  }
}
