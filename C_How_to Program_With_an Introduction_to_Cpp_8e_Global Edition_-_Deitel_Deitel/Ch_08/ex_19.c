#include <stdio.h>
#include <string.h>
#define SIZE 100

void dataPrompt(char *prompt);
void dataEntry(char *data);
void tokeniseText(char string[], char *word);

int main(void)
{
  char string[SIZE], remove[SIZE];
  char *text = "line of text", *word = "word";

  dataPrompt(text);
  dataEntry(string);
  dataPrompt(word);
  dataEntry(remove);
  puts("");
  tokeniseText(string, remove);
  puts("");

  for (size_t i = 0; i < SIZE; i++) {
    printf("%s", "");
  }
}

void dataPrompt(char *prompt)
{
  printf("\n%s%s%s\n\n%s", "Enter a ", prompt, ":", "> ");
}

void dataEntry(char *data)
{

  fgets(data, SIZE, stdin);

  int count = 0;

  while (data[count] != '\n') {
    count++;
  }

  data[count] = '\0';
}

void tokeniseText(char string[], char *word)
{
  int count = 0, removed = 0;
  char *stringPtr;

  stringPtr = strtok(string, " ");

  while (stringPtr != NULL) {

    int space = 0;
    
    if (strcmp(stringPtr, word) == 0) {
      stringPtr = strcpy(stringPtr, "");
      removed++;
      space--;
    }

    printf("%s", stringPtr);

    if (space == 0) {
      printf("%s", " ");
    }

    stringPtr = strtok(NULL, " ");
    count++;
  }
  printf("\n\n%s%s%s%d\n", "# words before ", word, " was removed: ", count);
  printf("%s%s%s%d\n", "# words after ", word, " was removed: ", count - removed);  
}
