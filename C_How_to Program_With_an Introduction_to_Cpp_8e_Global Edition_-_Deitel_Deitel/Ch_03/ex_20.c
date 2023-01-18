#include <stdio.h>

int main ( void )
{
  int totalHours;
  float hourlyRate, overtimePay, totalPay;

  puts( "Enter # hours worked (-1 to end):" );
  scanf( "%d", &totalHours );

  while ( totalHours != -1 ) {

    puts( "Enter hourly rate of the worker:" );
    scanf( "%f", &hourlyRate );

    if( totalHours > 40 ) {
      overtimePay = ( totalHours - 40 ) * hourlyRate * 1.5;
      totalPay = overtimePay + totalHours * hourlyRate;
    }
    else {
      totalPay = totalHours * hourlyRate;
    }
    
    printf( "Salary is $%.2f\n", totalPay );

    puts( "Enter # hours worked (-1 to end):" );
    scanf( "%d", &totalHours );

  }
}
