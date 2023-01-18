#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int playGame(int wager, int bankBalance);

enum Status {CONTINUE, WON, LOST};

int rollDice();

int main(void)
{
  srand(time(NULL));
  int bankBalance, originalBankBalance = 3;
  int wager = 0;
  int counter = 0;
  int numberOfGames = 0;
  int limit = 2;
  int total = 0;
  float average = 0;
  
  while (numberOfGames != limit) {
    counter = 0;
    bankBalance = originalBankBalance;
    
    while (bankBalance != 0) {
      wager = 1 + (rand() % bankBalance);
      printf("Wager: %d\n", wager);
      total = playGame(wager, bankBalance);

      if (total == 0) {
	bankBalance += wager;
      }
      else {
	bankBalance -= wager;
      }
      counter++;
      total += counter;
      printf("Bank balance: %d\n", bankBalance);
      printf("Game Count: %d\n", counter);
    }
    numberOfGames++;
  }
  average = (float) total / numberOfGames;
  printf("Average number of games: %.2f\n", average);
    printf("Number of times played: %d\n", total);
}

int rollDice(void)
{
  int die1 = 1 + (rand() % 6);
  int die2 = 1 + (rand() % 6);

  return die1 + die2;
}

int playGame(int wager, int bankBalance)
{
  int myPoint;
  enum Status gameStatus;
  int sum = rollDice();

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
    
    if (sum == myPoint) {
      gameStatus = WON;
      return 1;
    }
    else {
      if (7 == sum) {
	gameStatus = LOST;
	return 0;
      }
    }
  }

  if (WON == gameStatus) {
  }
  else {
  }
}
