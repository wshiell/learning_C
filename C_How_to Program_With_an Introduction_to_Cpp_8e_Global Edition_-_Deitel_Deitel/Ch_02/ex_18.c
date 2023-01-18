#include <stdio.h>

int main ( void )
{
  int highestRainfallSeason;
  int highestRainfallYear;

  puts( "Enter value for current seasons' highest rainfall: " );
  scanf( "%d", &highestRainfallSeason );

  puts( "Enter value for current year's highest rainfall: ");
  scanf( "%d", &highestRainfallYear);

  if ( highestRainfallSeason > highestRainfallYear ) {
    puts( "New Yearly Rainfall Record." );
    highestRainfallYear = highestRainfallSeason;
  }
}
