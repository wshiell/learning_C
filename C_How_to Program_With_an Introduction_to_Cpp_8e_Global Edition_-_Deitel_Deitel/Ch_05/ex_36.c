#include <stdio.h>

void hanoi(int numberOfDiscs, int initialPeg, int holdingPeg, int finalPeg);

int main(void)
{
  int numberOfDiscs, initialPeg = 1, holdingPeg = 2, finalPeg = 3;
  int temp;

  puts("Enter number of discs:");
  scanf("%d", &numberOfDiscs);
  puts("");

  hanoi(numberOfDiscs, initialPeg, holdingPeg, finalPeg);
}

void hanoi(int nthDisc, int initialPeg, int holdingPeg, int finalPeg)
{
  int initPeg, holdPeg, finPeg;
  
  if (nthDisc == 1) {

    printf("%d --> %d\n", initialPeg, finalPeg);
    return;
  }

  else {
    initPeg = initialPeg;
    finPeg = holdingPeg;
    holdPeg = finalPeg;

    hanoi((nthDisc - 1), initPeg, holdPeg, finPeg);

    printf("%d --> %d\n", initialPeg, finalPeg);

    initPeg = holdingPeg;
    holdPeg = initialPeg;
    finPeg = finalPeg;
    hanoi((nthDisc - 1), initPeg, holdPeg, finPeg);    
  }
}
