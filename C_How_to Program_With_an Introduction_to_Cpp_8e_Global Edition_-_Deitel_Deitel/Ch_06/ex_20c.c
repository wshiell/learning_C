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
  int gamesWon = 0;

  for (int count = 0; count < GAMES; count++) {
    results[count] = craps();

    if (results[count] != 0) {
      gamesWon++;
    }
  }

  for (int count1 = 0; count1 <= 20; count1++) {
  
    for (int count2 = 0; count2 < GAMES; count2++) {
  
      if (results[count2] == count1 + 1) {
	frequency[count1]++;
      }
      else {

	if (results[count2] > 20) {
	  frequency[20]++;
	}
	else {
	  ;
	}
      }
    }
  }

  for (int count = 0; count <= 20; count++) {

    if (count < 20) {
      printf("Number of games won on roll %d: %d\n", count + 1, frequency[count]);
    }
    else {
      printf("Number of games won after more than %d rolls: %d\n", count + 1, frequency[count]);
    }
  }

  printf("Games won (out of %d): %d\n", GAMES, gamesWon);
  printf("Percent of games won: %.2f%%\n", ((float) gamesWon / GAMES) * 100);
  
  puts("");
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

  if (WON == gameStatus) {
    return rolls;
  }
  else {
    return 0;
  }
}

int rollDice(void)
{
  int die1 = 1 + (rand() % 6);
  int die2 = 1 + (rand() % 6);

  return die1 + die2;
} 
