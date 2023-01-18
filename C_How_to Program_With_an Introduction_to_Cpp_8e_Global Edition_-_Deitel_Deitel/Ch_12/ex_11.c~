#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

struct listNode {
  char data;
  unsigned int marker;
  struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void menuInstructions(void);
void enterSentence(char value[SIZE]);
void sentenceStack(ListNodePtr *startPtr, char * value);
void reverse(ListNodePtr *startPtr);
void resetMarkers(ListNodePtr *startPtr);
void printList(ListNodePtr startPtr);

int main(void)
{
  char value[SIZE];
  int menuChoice;
  ListNodePtr startPtr = NULL;

  puts("\n*** Sentence Reversal Program ***\n");

  menuInstructions();
  scanf("%d", &menuChoice);
  
  while (menuChoice != 4) {

    switch (menuChoice) {

    case 1:
      enterSentence(value);    
      sentenceStack(&startPtr, value);
      break;
    case 2:
      printList(startPtr);
      break;
    case 3:
      reverse(&startPtr);
      printList(startPtr);
      resetMarkers(&startPtr);
      break;
    default:
      puts("\nInvalid choice. Please enter again.");
    }
      
    menuInstructions();
    scanf("%d", &menuChoice);
  }
}

void menuInstructions(void)
{
  printf("\n%s\n%s\n%s\n%s\n\n%s",
	 "1 - Enter sentence.", "2 - Use stack to reverse order.",
	 "3 - Print in proper order.", "4 - Quit Program.", "> ");
}

void enterSentence(char value[SIZE])
{
  getchar();
  printf("\n%s\n\n%s", "Enter a sentence:", "> ");
  fgets(value, SIZE, stdin);

  int length = strlen(value);

  value[length - 1] = '\0';
}

void sentenceStack(ListNodePtr *startPtr, char * value)
{
  int i = 0, length = strlen(value);
  char c;
  
  while (i < length) {

    c = value[i++];
    
    ListNodePtr newPtr = malloc(sizeof(ListNode));

    if (newPtr != NULL) {
      newPtr->data = c;
      newPtr->marker = 0;
      newPtr->nextPtr = NULL;

      ListNodePtr topPtr = NULL;

      if (topPtr == NULL) {
	newPtr->nextPtr = *startPtr;
	*startPtr = newPtr;
      }
      else {
	topPtr->nextPtr = newPtr;
	newPtr->nextPtr = *startPtr;
      }
    }
    else {
      printf("\n%s%s\n", value, " not inserted. No memory available.");
    }
  }
}

void reverse(ListNodePtr *startPtr)
{
  if (*startPtr != NULL) {
  
    if ((*startPtr)->nextPtr != NULL) {
      ListNodePtr currentPtr = *startPtr;
      char first = (*startPtr)->data;

      while (currentPtr->nextPtr != NULL && (currentPtr->nextPtr)->marker != 1) {
	currentPtr = currentPtr->nextPtr;
      }

      ListNodePtr tempPtr = *startPtr;
 
      (*startPtr)->data = currentPtr->data;
      *startPtr = currentPtr;
      (*startPtr)->data = first;
      (*startPtr)->marker = 1;
      *startPtr = tempPtr;
      reverse(&(*startPtr)->nextPtr);
    }
  }
  else {
    ;
  }
}

void resetMarkers(ListNodePtr *startPtr)
{
  if (*startPtr != NULL) {
  
    ListNodePtr tempPtr = *startPtr;
  
    do {

      (*startPtr)->marker = 0;
      *startPtr = (*startPtr)->nextPtr;
    
    } while (*startPtr != NULL);

    *startPtr = tempPtr;
  }
  else {
    ;
  }
}

void printList(ListNodePtr startPtr)
{
  if (startPtr != NULL) {

    puts("");

    while (startPtr != NULL) {

      printf("%c%s",startPtr->data, "");
      startPtr = startPtr->nextPtr;
    }
    puts("");
  }
  else {
    puts("\nNo sentence entered.");
  }
}
