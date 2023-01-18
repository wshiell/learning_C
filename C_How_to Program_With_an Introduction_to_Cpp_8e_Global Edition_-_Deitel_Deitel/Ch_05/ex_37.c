#include <stdio.h>

void hanoi(int numberOfDiscs, int initialPeg, int holdingPeg, int finalPeg);

int main(void)
{
  int numberOfDiscs, initialPeg = 1, holdingPeg = 2, finalPeg = 1;

  puts("Enter number of discs:");
  scanf("%d", &numberOfDiscs);

  hanoi(numberOfDiscs, initialPeg, holdingPeg, finalPeg);
}

void hanoi(int numberOfDiscs, int initialPeg, int holdingPeg, int finalPeg)
{
  int initPeg, holdPeg, finPeg;

  for (int counter = 1; counter <= numberOfDiscs; counter++) {

    printf("%d --> %d\n)", initialPeg, finalPeg);

    initPeg = initialPeg;
    holdPeg = finalPeg;
    finPeg = holdingPeg;
    
    initPeg = initialPeg;
    holdPeg = finalPeg;
    finPeg = holdingPeg;
      
    printf("%d --> %d\n", initialPeg, finalPeg);
      
  }
}
