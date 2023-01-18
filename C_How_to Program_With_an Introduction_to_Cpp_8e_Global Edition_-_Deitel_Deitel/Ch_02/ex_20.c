#include <stdio.h>

int main ( void )
{

  int hours, minutes, seconds, total;

  puts( "Enter total time (in seconds): " );
  scanf( "%d", &total );

  hours = total / 3600;
  minutes = ( total - hours * 3600 ) / 60;
  seconds = total - hours * 3600 - minutes * 60;

  printf( "%s",  "Time in hours: minutes: seconds is: ");
  printf( "%d hours:%d minutes:%d seconds.\n\n", hours, minutes, seconds );

}
