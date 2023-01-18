#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

void printLatinWord(char* token, int count);

int main(void)
{
  int count = 0;
  char originalPhrase[SIZE];
  char *tokenPtr;

  puts("Enter a sentence to be converted to pig latin:");
  fgets(originalPhrase, SIZE, stdin);

  tokenPtr = strtok(originalPhrase, " ");
  puts("\nThe phrase converted to pig latin is: ");
  
  while (tokenPtr != NULL) {

    printLatinWord(tokenPtr, count);
    count++;    
    tokenPtr = strtok(NULL, " ");
  }
  puts("\nProgram End.");
}

void printLatinWord(char* token, int count)
{
  char *pigLatin = "ay";
  char c, d;

  if (count == 0) {
    c = toupper(token[1]);
    d = tolower(token[0]);
  }
  else {
    c = token[1];
    d = token[0];
  }
  
  printf("%c%s%c%s ", c, &token[2], d, pigLatin);
}
