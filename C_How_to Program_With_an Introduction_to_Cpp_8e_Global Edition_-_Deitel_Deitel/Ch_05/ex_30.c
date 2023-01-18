#include <stdio.h>

int toQualityPoints(float average);

int main(void)
{
  float average;
  int quality;

  puts("Enter average grade:");
  scanf("%f", &average);
  quality = toQualityPoints(average);
  
  printf("Quality of average %f is: %d\n", average, quality);
}

int toQualityPoints(float average)
{
  if (average >= 60) {

    
    if (average >= 70) {

      
      if (average >= 80) {

	
	if (average >= 90) {
	  return 1;
	}
	return 2;
      }
      return 3;
    }
    return 4;
  }
  else {
    return 0;
  }
}
