#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
  srand(time(NULL));

  int guess, number;
  char quit, counter = 0;

  number = 1 + rand() % 1000;
  printf("Number: %d\n", number);
  puts("I have a number between 1 and 1000.");
  puts("Can you guess my number");
  puts("Please type in your first guess.");
  scanf("%d", &guess);
  
  while ((quit = getchar()) != 'n') {

    if (counter != 0) {
      number = 1 + rand() % 1000;
      printf("Number: %d\n", number);
      puts("I have a number between 1 and 1000.");
      puts("Can you guess my number");
      puts("Please type in your first guess.");
      scanf("%d", &guess);
      counter--;
    }

    if (guess == number) {
      puts("Excellent! You guessed the number!");
      puts("Would you like to play again? (y or n)");
      scanf("%d", &guess);
      counter++;
    }
    else {
      if (guess < number) {
	puts("Too low. Guess again.");
	scanf("%d", &guess);
      }
      if (guess > number) {
        puts("Too high. Guess again.");
	scanf("%d", &guess);
      }
    }
  }
}



