#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
  srand(time(NULL));

  int guess, number, guessCount = 0;
  char quit, counter = 0;

  number = 1 + rand() % 1000;
  printf("Number: %d\n", number);
  puts("I have a number between 1 and 1000.");
  puts("Can you guess my number");
  puts("Please type in your first guess.");
  scanf("%d", &guess);
  guessCount++;
  
  while ((quit = getchar()) != 'n') {

    if (counter != 0) {

      number = 1 + rand() % 1000;
      printf("Number: %d\n", number);
      puts("I have a number between 1 and 1000.");
      puts("Can you guess my number");
      puts("Please type in your first guess.");
      scanf("%d", &guess);
      guessCount++;
      counter--;
    }

    if (guess == number) {

      if (guessCount < 10) {
	puts("Either you know the secret, or you got lucky!");
      }
      else {

        if (guessCount == 10) {
	  puts("Ah ha! You know the secret!");
	}
	else {
	  puts("You should be able to do better!");
	}
      }
      puts("Excellent! You guessed the number!");
      puts("Would you like to play again? (y or n)");
      scanf("%d", &guess);
      counter++;
      guessCount = 0;
    }
    else {
      if (guess < number) {
	puts("Too low. Guess again.");
	scanf("%d", &guess);
	guessCount++;
      }
      if (guess > number) {
        puts("Too high. Guess again.");
	scanf("%d", &guess);
	guessCount++;
      }
    }
  }
}



