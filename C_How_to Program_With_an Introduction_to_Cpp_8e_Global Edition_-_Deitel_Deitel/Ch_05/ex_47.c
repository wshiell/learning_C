#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Status {CONTINUE, WON, LOST};

int playGame(int wager, int bankBalance);
int rollDice(void);
void banter(int wager, int bankBalance, int oldBankBalance, int newBankBalance);

int main(void)
{

  srand(time(NULL));

  int oldBankBalance, newBankBalance, bankBalance = 1000, wager;

  puts("\n\n*****Welcome to Wade's Craps Simulator*****\n");
  printf("\nCurrent Bank Balance: $%d**\n\n", bankBalance);
  printf("%s", "Enter a wager, or type -1 to quit: $");
  scanf("%d", &wager);

  newBankBalance = oldBankBalance = bankBalance;
  
  banter(wager, bankBalance, oldBankBalance, newBankBalance);

  if (wager == -1) {
    bankBalance = 0;
  }
  
  while ((wager != -1) || (bankBalance != 0)) {

    while ((wager <= 0) || (wager > bankBalance)) {
      puts("Wager invalid. Please re-enter.");
      printf("%s", "Enter a wager: $");
      scanf("%df", &wager);

      banter(wager, bankBalance, oldBankBalance, newBankBalance);
    }

    oldBankBalance = bankBalance;
    bankBalance = playGame(wager, bankBalance);
    newBankBalance = bankBalance;

    printf("\nCurrent Bank Balance: $%d**\n\n", bankBalance);

    if (bankBalance == 0) {
      banter(wager, bankBalance, oldBankBalance, newBankBalance);
      break;
    }
    else {
      printf("%s", "\nEnter a wager, or type -1 to quit: $");
      scanf("%d", &wager);

      if (wager == -1) {
	newBankBalance = 0;
        banter(wager, bankBalance, oldBankBalance, newBankBalance);
        break;
      }
      else {
        newBankBalance = newBankBalance - wager;
        banter(wager, bankBalance, oldBankBalance, newBankBalance);
      }
    }
  }  
}

int playGame(int wager, int bankBalance)
{
  enum Status gameStatus;
  int sum = rollDice(), myPoint;

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
    printf("\n**Point is %d**\n\n", myPoint);
    break;
  }

  while (CONTINUE == gameStatus) {
    sum = rollDice();
    
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
    bankBalance += wager;
    puts("\n\n**Player wins**\n");
    return bankBalance;
  }
  else {
    bankBalance -= wager;
    puts("\n\n**Player loses**\n");
    return bankBalance;
  }
}

int rollDice(void)
{
  int die1 = 1 + (rand() % 6);
  int die2 = 1 + (rand() % 6);

  printf("Player rolled %d + %d = %d\n", die1, die2, die1 + die2);
  return die1 + die2;
}

void banter(int wager, int bankBalance, int oldBankBalance, int newBankBalance)
{

  if (wager == bankBalance) {
    puts("\n**Oh, so you're going for broke, huh**?\n");
  }

  if ((wager < bankBalance / 2) && (wager != -1)) {
    puts("\n**Aww, come on, take a chance!**\n");
  }

  if (newBankBalance >= 2 * oldBankBalance) {
    puts("\n**You're up big, now's the time to cash in your chips!**\n");
  }

  if (bankBalance == 0) {
      puts("\n**Sorry, you busted :(**\n");
  }

  if ((wager == -1) || (bankBalance == 0)) {
    puts("\n**Thanks for playing! Come back soon**\n");
  }
}
