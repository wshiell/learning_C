#include <stdio.h>

int main ( void )
{

  int milesDriven, costPerGallon, averageMiles, parking, tolls;
  int dailyCost;

  puts( "Enter miles driven today: " );
  scanf( "%d", &milesDriven );

  puts( "Enter cost per gallon: " );
  scanf( "%d", &costPerGallon );

  puts( "Enter average miles per gallon: " );
  scanf( "%d", &averageMiles );

  puts( "Enter parking fees: " );
  scanf( "%d", &parking );

  puts( "Enter tolls per day: " );
  scanf( "%d", &tolls );

  dailyCost = tolls + parking + milesDriven * costPerGallon / averageMiles;
  
  printf( "Total daily cost of driving is: %d\n", dailyCost );
}
