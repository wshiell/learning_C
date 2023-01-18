#include <stdio.h>
#include <string.h>
#define SIZE 100

void reverseLetters(char *sentencePtr);
void reverseTokens(char *wordList[SIZE], int count);

int main(void)
{
  int count = 0;
  char c;
  char sentence[SIZE];
  char *wordList[SIZE];
  char *sentencePtr;
  
  puts("Enter a sentence:");
  fgets(sentence, SIZE, stdin);

  c = sentence[count];
  
  while (c != '\n') {
    count++;
    c = sentence[count];
  }
  sentence[count] = '\0';
  count = 0;
  
  wordList[count] = sentencePtr = strtok(sentence, " ");
  
  while (sentencePtr != NULL) {

    count++;
    reverseLetters(sentencePtr);
    wordList[count] = sentencePtr = strtok(NULL, " ");
    printf("%s", " ");
  }
  puts("");
  
  reverseTokens(wordList, count);
  
  puts("");
}

void reverseLetters(char *sentencePtr)
{
  int length;
  
  length = strlen(sentencePtr);

  for (int i = length - 1; i >= 0; i--) {
    printf("%c", sentencePtr[i]);
  }
}

void reverseTokens(char *wordList[SIZE], int count)
{
  for (int i = count - 1; i >= 0; i--) {
    printf("%s ", wordList[i]);
  }
}
