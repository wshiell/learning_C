#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listNode {
  char data;
  unsigned int marker;
  struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void menuInstructions(void);
char chooseCharacter(void);
void insertCharacter(ListNodePtr *startPtr, char value);
void reverse(ListNodePtr *startPtr);
void resetMarkers(ListNodePtr *startPtr);
void printList(ListNodePtr startPtr);

int main(void)
{
  char value;
  int menuChoice;
  ListNodePtr startPtr = NULL;

  puts("*** Forward and Reversed Character List ***");

  menuInstructions();
  scanf("%d", &menuChoice);
  
  while (menuChoice != 4) {

    switch (menuChoice) {

    case 1:
      value = chooseCharacter();    
      insertCharacter(&startPtr, value);
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
	 "1 - Enter character.", "2 - Print in proper order.",
	 "3 - Print in reverse order.", "4 - Quit Program.", "> ");
}

char chooseCharacter(void)
{
  char character;
  printf("\n%s\n\n%s", "Enter a character:", "> ");
  scanf("\n%c", &character);

  return character;
}

void insertCharacter(ListNodePtr *startPtr, char value)
{
  ListNodePtr newPtr = malloc(sizeof(ListNode));

  if (newPtr != NULL) {
    newPtr->data = value;
    newPtr->marker = 0;
    newPtr->nextPtr = NULL;

    ListNodePtr previousPtr = NULL;
    ListNodePtr currentPtr = *startPtr;
  
    while (currentPtr != NULL && value > currentPtr->data) {

      previousPtr = currentPtr;
      currentPtr = currentPtr->nextPtr;
    }

    if (previousPtr == NULL) {
      newPtr->nextPtr = *startPtr;
      *startPtr = newPtr;
    }
    else {
      previousPtr->nextPtr = newPtr;
      newPtr->nextPtr = currentPtr;
    }
  }
  else {
    printf("\n%c%s\n", value, " not inserted. No memory available.");
  }
}

void reverse(ListNodePtr *startPtr)
{
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

void resetMarkers(ListNodePtr *startPtr)
{
  ListNodePtr tempPtr = *startPtr;
  
  do {

    (*startPtr)->marker = 0;
    *startPtr = (*startPtr)->nextPtr;
    
  } while (*startPtr != NULL);

  *startPtr = tempPtr;
}

void printList(ListNodePtr startPtr)
{
  if (startPtr != NULL) {

    puts("\nThe list is:\n");
    
    while (startPtr != NULL) {

      printf("%c%s",startPtr->data, " --> ");
      startPtr = startPtr->nextPtr;
    }
    puts("NULL");
  }
  else {
    puts("\nList is empty.");
  }
}
