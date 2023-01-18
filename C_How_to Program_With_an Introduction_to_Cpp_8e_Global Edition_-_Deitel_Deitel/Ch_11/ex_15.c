#include <stdio.h>
#define SIZE 80

int main(void)
{
  FILE *inputPtr, *outputPtr;
  char sentence[SIZE], inputName[20], outputName[20];
  int choice, c, i = 0;

  printf("%s\n%s\n%s\n\n%s", "Would you like to enter a sentence and output",
	 "it to the screen, or read from a file and write to a file?",
	 "(1 - keyboard, 2 - file)", "> ");
  scanf("%d", &choice);
  getchar();
  
  if (choice == 1) {
  
    puts("Enter a line of text:");

    while ((i < SIZE - 1) && (c = getchar()) != '\n') {
      sentence[i++] = c;
    }

    sentence[i] = '\0';

    puts("\nThe line entered was:");
    puts(sentence);
  }
  else {
    
    printf("%s\n\n%s", "Enter the name of the input file:", "> ");
    scanf("%s", inputName);

    printf("%s\n\n%s", "Enter the name of the output file:", "> ");
    scanf("%s", outputName);

    if ((inputPtr = fopen(inputName, "rb")) == NULL) {
      puts("File cannot be opened.");
    }
    else {

      while ((i < SIZE - 1) && (c = fgetc(inputPtr)) != '\n') {

    	sentence[i++] = c;
      }

      sentence[i] = '\0';
    }
    
    fclose(inputPtr);

    if ((outputPtr = fopen(outputName, "wb")) == NULL) {
      puts("File cannot be opened.");      
    }
    else {
      fputs(sentence, outputPtr);
      printf("Sentence: %s\n", sentence);
    }

    fclose(outputPtr);
  }
}
