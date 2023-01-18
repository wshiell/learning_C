#include <stdio.h>
#include <stdlib.h>

struct listNode {
  char character;
  struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void menuInstructions(void);
void listInstructions(void);
char chooseCharacter(void);
void insertCharacter(ListNodePtr **chosenPtr, char value);
void deleteCharacter(ListNodePtr **chosenPtr, char value);
void printList(ListNodePtr chosenPtr);
int isEmpty(ListNodePtr chosenPtr);
void concatenate(ListNodePtr *startPtr1, ListNodePtr startPtr2);

int main(void)
{
  char value;
  int listChoice, menuChoice;
  ListNodePtr startPtr1 = NULL, startPtr2 = NULL, *chosenPtr = NULL;

  puts("*** Concatenating Two Lists of Characters ***");

  menuInstructions();
  scanf("%d", &menuChoice);
  
  while (menuChoice != 4) {

    if (menuChoice != 3) {

      if (menuChoice == 1) {
	chosenPtr = &startPtr1;
      }
      else {
	chosenPtr = &startPtr2;    
      }

      listInstructions();
      scanf("%d", &listChoice);

      while (listChoice != 4) {

	switch (listChoice) {

	case 1:
	  value = chooseCharacter();    
	  insertCharacter(&chosenPtr, value);
	  break;
	case 2:

	  if (!isEmpty(*chosenPtr)) {
	    value = chooseCharacter();
	    deleteCharacter(&chosenPtr, value);
	  }
	  else {
	    puts("\nList is empty.");
	  }
	  break;
	case 3:
	  printList(*chosenPtr);
	  break;
	default:
	  puts("\nInvalid choice. Please enter again.");
	}
      
	listInstructions();
	scanf("%d", &listChoice);
      }
    }
    else {
      concatenate(&startPtr1, startPtr2);
    }

    menuInstructions();
    scanf("%d", &menuChoice);
  }
}

void menuInstructions(void)
{
  printf("\n%s\n%s\n%s\n%s\n\n%s",
	 "1 - Select List 1.", "2 - Select List 2.",
	 "3 - Concatenate Lists.", "4 - Quit Program.", "> ");
}

void listInstructions(void)
{
  printf("\n%s\n%s\n%s\n%s\n\n%s",	 
	 "1 - Insert a character.", "2 - Delete a character.",
	 "3 - Print List.", "4 - Return to Main Menu.", "> ");
}

char chooseCharacter(void)
{
  char c;
  printf("\n%s\n\n%s", "Enter a character:", "> ");
  scanf("\n%c", &c);

  return c;
}

void insertCharacter(ListNodePtr **chosenPtr, char value)
{
  ListNodePtr newPtr = malloc(sizeof(ListNode));

  if (newPtr != NULL) {
    newPtr->character = value;
    newPtr->nextPtr = NULL;

    ListNodePtr previousPtr = NULL;
    ListNodePtr currentPtr = **chosenPtr;
  
    while (currentPtr != NULL && value > currentPtr->character) {

      previousPtr = currentPtr;
      currentPtr = currentPtr->nextPtr;
    }

    if (previousPtr == NULL) {
      newPtr->nextPtr = **chosenPtr;
      **chosenPtr = newPtr;
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

void deleteCharacter(ListNodePtr **chosenPtr, char value)
{
  if (value == ((**chosenPtr)->character)) {
    ListNodePtr tempPtr = **chosenPtr;
    char tempValue = value;
    **chosenPtr = (**chosenPtr)->nextPtr;
    free(tempPtr);
    printf("\n%s%c%s\n", "Character ", tempValue, " was deleted.");
  }
  else {
  
    ListNodePtr previousPtr = NULL;
    ListNodePtr currentPtr = **chosenPtr;

    if (currentPtr != NULL) {

      while (currentPtr != NULL && currentPtr->character != value) {
	previousPtr = currentPtr;
	currentPtr = currentPtr->nextPtr;
      }

      if (currentPtr != NULL) {
	ListNodePtr tempPtr = currentPtr;
	char tempValue = value;	
	previousPtr->nextPtr = currentPtr->nextPtr;
	free(tempPtr);
	printf("\n%s%c%s\n", "Character ", tempValue, " was deleted.");
      }
      else {
	printf("\n%s%c%s\n", "Character ", value, " was not found in list.");
      }
    }
  }
}

void printList(ListNodePtr chosenPtr)
{
  if (chosenPtr != NULL) {

    puts("\nThe list is:\n");    
    while (chosenPtr != NULL) {

      printf("%c%s", chosenPtr->character, " --> ");
      chosenPtr = chosenPtr->nextPtr;
    }
    puts("NULL");
  }
  else {
    puts("\nList is empty.");
  }
}

int isEmpty(ListNodePtr chosenPtr)
{
  return chosenPtr == NULL;
}

void concatenate(ListNodePtr *startPtr1, ListNodePtr startPtr2)
{
  if (*startPtr1 == NULL) {

    if (startPtr2 == NULL) {
      puts("Both lists are empty.");
    }
    else {
      puts("List 1 is empty. List 2 is:");
      printList(startPtr2);
    }
  }
  else {

    if (startPtr2 == NULL) {
      puts("List 2 is empty.\nList 1 is:");
      printList(*startPtr1);	
    }
    else {
      ListNodePtr previousPtr = NULL;
      ListNodePtr currentPtr = *startPtr1;

      while (currentPtr != NULL) {
	previousPtr = currentPtr;
	currentPtr = currentPtr->nextPtr;
      }
      previousPtr->nextPtr = startPtr2;
      printList(*startPtr1);
    }
  }
}
