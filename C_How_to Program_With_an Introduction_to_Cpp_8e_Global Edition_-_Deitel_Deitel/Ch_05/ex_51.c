#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void askQuestion(void);

int main(void)
{
  askQuestion();
}

void askQuestion(void)
{
  int answer, guess, number1, number2;
  int tally = 0, wrong = 0;
  float percentage;
  
  while (tally < 10) {
    srand(time(NULL));

    number1 = 1 + rand() % 9;
    number2 = 1 + rand() % 9;

    answer = number1 * number2;
  
    puts("Multiplication Practice Quiz\n");
  
    printf("How much is %d times %d?\n", number1, number2);

    scanf("%d", &guess);
    
    while(guess != answer) {
      tally++;
      wrong++;
      puts("Wrong.");
      scanf("%d", &guess);

      if (tally >= 10) {
	break;
      }
    }
    
    if (tally < 10) {
      tally++;
      puts("Guess.");
      scanf("%d", &guess);
    }
    else {
      percentage = (float) (tally - wrong) / tally;
      
      if (percentage > .75) {
	puts("Yay.");
      }
      else {
	puts("Boo.");
      }
    }
  }
}
