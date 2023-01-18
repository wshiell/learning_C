#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GAMES 2000000

enum Status {CONTINUE, WON, LOST};

int craps(void); 
int rollDice(void);

int main(void)
{
  srand(time(NULL));

  int results[GAMES];
  int frequency[20] = {0};
  double averageRolls;
  double sum = 0;

  for (int count = 0; count < GAMES; count++) {
    results[count] = craps();
    sum += results[count];
  }

  averageRolls = sum / GAMES;

  printf("\nAverage number of rolls: %.6f\n", averageRolls);
}

int craps(void) {

  enum Status gameStatus;
  int myPoint;
  int rolls = 0; 
  int sum = rollDice();
  rolls++;

  switch(sum) {

  case 7:
  case 11:
    gameStatus = WON;
    break;

  case 2:
  case 3:
  case 12:
    gameStatus = LOST;
    break;

  default:
    gameStatus = CONTINUE;
    myPoint = sum;
    break;
  }

  while (CONTINUE == gameStatus) {
    sum = rollDice();
    rolls++;
    
    if (sum == myPoint) {
      gameStatus = WON;
    }
    else {
      if (7 == sum) {
	gameStatus = LOST;
      }
    }
  }

  return rolls;

}

int rollDice(void)
{
  int die1 = 1 + (rand() % 6);
  int die2 = 1 + (rand() % 6);

  return die1 + die2;
} 
