#include <stdio.h>

int main ( void )
{

  float population = 7.2, growth_rate = 0.0109;;
  int i, current_year = 2018, year;

  puts( "Enter year:" );
  scanf( "%d", &year );

  i = year - current_year;

  while( i > 0 ) {
    population = population + growth_rate * population;
    i--;
  }
  
  printf( "\nWorld population in %d will be:\t%f\n\n", year, population );

}
