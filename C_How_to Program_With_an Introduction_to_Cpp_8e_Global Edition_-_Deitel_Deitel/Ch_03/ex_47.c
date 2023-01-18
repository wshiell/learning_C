#include <stdio.h>

int main( void )
{

  int max_rate, target_rate;
  int birthDay, birthMonth, birthYear;
  int currentDay = 9, currentMonth = 10, currentYear = 2018;
  int totalDays, totalMonths, totalYears;
  int day, month, year;
  int ageDays, ageMonths, ageYears;
  int days, daysMonth, daysYear;
  float currentAge;

  puts( "Enter birthday (day/month/year):" );
  scanf( "%d%d%d", &birthDay, &birthMonth, &birthYear );

  if( currentDay < birthDay ) {
    month = currentMonth - 1;
    day = birthDay - currentDay;
  }
  else {
    totalDays = currentDay - birthDay;
  }
  if( currentMonth < birthMonth ) {
    year = currentYear - 1;
    month = birthMonth - currentMonth;
  }
  else{
    totalMonths = currentMonth - birthMonth;
  }

  currentMonth = month;
  /* currentYear = year; */

  /* totalYears = currentYear - birthYear; */
  printf( "Age in (days/months/years): %d/%d/%d/\n", totalDays, totalMonths,
	  totalYears );


  totalMonths = month;
  totalDays = day;

  /* ageYears = ( float ) days / 365.24; */
  /* max_rate = 220 - ageYears; */

  /* printf( "Age (in years): %f", ageYears ); */
  /* printf( "Maximum heart rate: %d.\n", max_rate ); */
  /* printf( "Target rate range: %f to %f.\n", .5 * max_rate, .85 * max_rate ); */
}
