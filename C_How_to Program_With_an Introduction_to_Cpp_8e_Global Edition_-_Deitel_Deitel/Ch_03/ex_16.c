#include <stdio.h>

int main ( void )
{

  float totalSales, totalIncome, totalTax, stateTax, countyTax;
  //  char *p = "month";
  float stateTaxRate = .04, countyTaxRate = .05;

  puts( "Enter total amount collected (-1 to quit): " );
  scanf( "%f", &totalSales );

  //  puts( "Enter month: " );
  //  scanf( "%c", &*p );

  while ( totalSales != -1 ) {

    stateTax = totalSales * stateTaxRate;
    countyTax = totalSales * countyTaxRate;
    totalTax = stateTax + countyTax;
    totalIncome = totalSales + totalTax;

    printf( "Total Collections: $%.2f\n", totalIncome );
    printf( "Total sales: $%.2f\n", totalSales );
    printf( "Total county tax: $%.2f\n", countyTax );
    printf( "Total state tax: $%.2f\n", stateTax );
    printf( "Total tax: $%.2f\n", totalTax );
    
    puts( "Enter total amount collected (-1 to quit): " );
    scanf( "%f", &totalSales );
    
    //  puts( "Enter month: " );
    //  scanf( "%c", &*p );
  }
}
