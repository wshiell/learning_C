#include <stdio.h>
#include <string.h>
#define SIZE 100

int enterString(void);
void dataPrompt(void);
void dataEntry(char *data);
int tokeniseText(char string[]);

int main(void)
{
  int sum = 0, oldSum, quit = 0;

  puts("Word Counting Program");
  puts("(Type 'q' to quit)");

  do {

    oldSum = sum;
    sum += enterString();

    printf("\n%s%d\n", "Running total: ", sum);
    
    if (sum == oldSum) {
      quit = -1;
    }
    
  } while (quit != -1);

  printf("\nTotal words entered: %d\n", sum);
}

int enterString(void)
{
  int total = 0;
  char string[SIZE];

  dataPrompt();
  dataEntry(string);

  if (string[0] == 'q') {
    return 0;
  }
  
  total += tokeniseText(string);

  return total;
}

void dataPrompt(void)
{
  printf("%s\n\n%s", "\nEnter a line of text:", "> ");
}

void dataEntry(char *data)
{

  fgets(data, SIZE, stdin);

  if (data[0] == 'q') {
    return;
  }
  
  int count = 0;

  while (data[count] != '\n') {
    count++;
  }

  data[count] = '\0';
}

int tokeniseText(char string[])
{
  int count = 0;
  char *stringPtr;

  stringPtr = strtok(string, " ");

  while (stringPtr != NULL) {

    stringPtr = strtok(NULL, " ");
    count++;
  }

  return count;
}

