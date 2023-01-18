#include <stdio.h>
#include <math.h>
#define SIZE 20

int main(void)
{
  int xNeg, xPos;
  int radius = 16;
  int line[SIZE] = {0};

  xNeg = -sqrt(radius);
  xPos = sqrt(radius);
  
  for (int i = 0; i < SIZE; i++) {

    if ( i == xNeg + SIZE / 2 || i == xPos + SIZE / 2) {
	line[i] = 1;
    }
      else {
	line[i] = 0;
	
      }
  }
    int counter = 0;
    
    for (int i = 0; i < SIZE; i++) {
      printf("%d ", line[i]);

      if (counter % SIZE + 1 == 0) {
	puts("");
      }
      counter++;
    }
  puts("");
}

