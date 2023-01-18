#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int askQuestion(void);

int main(void)
{
  int answer;
  
  answer = askQuestion();

  while (answer != -1) {
    answer = askQuestion();
  }
}

int askQuestion(void)
{
  int answer, guess, number1, number2;
  
  srand(time(NULL));

  number1 = 1 + rand() % 9;
  number2 = 1 + rand() % 9;

  puts("Multiplication Practice Quiz (type -1 to quit)\n");
  
  printf("How much is %d times %d?\n", number1, number2);
  scanf("%d", &guess);
  
  answer = number1 * number2;

  if (guess != -1) {

    while (guess != answer) {
      puts("No. Please try again.");
      scanf("%d", &guess);
    }

    puts("Very good!\n");
    puts("Would you like to play again? (type 1 to play, -1 to quit)");
    scanf("%d", &guess);
      return guess;
  }
  else {
    return guess;
  }
}
