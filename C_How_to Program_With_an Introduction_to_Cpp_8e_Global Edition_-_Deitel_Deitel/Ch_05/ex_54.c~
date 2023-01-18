#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void askQuestion(int level);

int main(void)
{
  int level, studentNumber = 0;
  
  puts("\nWelcome to the Multiplication Practice Quiz.");
  puts("(type -1 to quit)\n");
  puts("Enter student number:\n");
  scanf("%d", &studentNumber);

  if (studentNumber != -1) {
    puts("Enter difficulty level (1 - 4):");
    scanf("%d", &level);
  }

  while (studentNumber != -1){  

    askQuestion(level); 

    puts("\nWelcome to the Multiplication Practice Quiz.");
    puts("(type -1 to quit)\n");
    puts("Enter student number:\n");
    scanf("%d", &studentNumber);

    if (studentNumber == -1) {
      break;
    }

    puts("Enter difficulty level (1 - 4):");
    scanf("%d", &level);
  } 
}

void askQuestion(int level)
{

  int correct = 0, incorrect = 0, responses = 0, answer, guess, number1, number2;
  int right, wrong;
  float percentageCorrect;
  
  while (responses < 10) { 

    srand(time(NULL));

    if (level == 1) {
      number1 = 1 + rand() % 9;
      number2 = 1 + rand() % 9;      
    }
    else {
      if (level == 2) {
	number1 = 100 + rand() % 99;
	number2 = 100 + rand() % 99;      
      }
      else {
	if (level == 3) {
	  number1 = 1000 + rand() % 999;
	  number2 = 1000 + rand() % 999;      
	}
	else {
	  number1 = 10000 + rand() % 9999;
	  number2 = 10000 + rand() % 9999;      
	}
      }
    }
    answer = number1 * number2;
    
    printf("Ready? Go!\n\nHow much is %d times %d?\n", number1, number2);
    scanf("%d", &guess);
    responses++;
    printf("Responses: %d\n", responses);    

    if (answer == guess) {

      right = 1 + rand() % 4;
      
      switch (right) {
      case 1:
	puts("You got it!");
	break;
      case 2:
	puts("Correct!");	
	break;
      case 3:
	puts("Correct!");	
	break;
      case 4:	
	puts("Correct!");
	break;
      }
      correct++;
    }
    else { 

      while (answer != guess && responses < 10) {

	wrong = 1 + rand() % 4;
      
	switch (wrong) {
	case 1:
	  puts("Incorrect. Please try again.");	
          break;
	case 2:
	  puts("Not quite! One more time.");	
          break;
	case 3:
	  puts("Sorry :( Have another go");	
          break;
        case 4:	
	  puts("Missed it. Try again!");
	  break;
	}

        scanf("%d", &guess);
	responses++;
	incorrect++;
	printf("Responses: %d\n", responses);

	if (answer == guess) {
	  correct++;
	}
      }
    }
  }

  percentageCorrect = (float) correct / responses; 
  
  if (percentageCorrect >= .75) { 
    printf("\nPercentage correct: %.2f%%\n", 100 * percentageCorrect);
    puts("Congratulations! You may proceed to the next level.");
  }
  else { 
    printf("\nPercentage correct: %.2f%%\n", 100 * percentageCorrect);
    puts("Please see your teacher for some extra help.");
  }
}
