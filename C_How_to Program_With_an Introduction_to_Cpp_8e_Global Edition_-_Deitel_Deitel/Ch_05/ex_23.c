#include <stdio.h>
#include <stdlib.h>

int time(int hours, int minutes, int seconds);

int main(void)
{
  int timeDifference, time1, time2, hours, minutes, seconds;
  
  puts("Enter number of hours, minutes and seconds for time 1:");
  scanf("%d%d%d", &hours, &minutes, &seconds);

  time1 = time(hours, minutes, seconds);

  puts("Enter number of hours, minutes and seconds for time 2:");
  scanf("%d%d%d", &hours, &minutes, &seconds);
  
  time2 = time(hours, minutes, seconds);

  timeDifference = time2 - time1;
  
  printf("\nTime between time 1 and time 2 (in seconds) is: %d\n",
	 abs(timeDifference));
  
}

int time(int hours, int minutes, int seconds)
{
  int totalTime;

  totalTime = 3600 * hours + 60 * minutes + seconds;
  return totalTime;
}
