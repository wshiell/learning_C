#include <stdio.h>
#include <stdlib.h>

struct listNode {
  int integer;
  struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void menuInstructions(void);
void listInstructions(void);
int  chooseInteger(void);
void insertInteger(ListNodePtr **chosenPtr, int value);
void deleteInteger(ListNodePtr **chosenPtr, int value);
void printList(ListNodePtr chosenPtr);
int isEmpty(ListNodePtr chosenPtr);
ListNodePtr merge(ListNodePtr *startPtr1, ListNodePtr startPtr2);

int main(void)
{
  int value;
  int listChoice, menuChoice;
  ListNodePtr startPtr1 = NULL, startPtr2 = NULL, *chosenPtr = NULL;

  puts("*** Concatenating Two Lists of Ordered Integers ***");

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
	  value = chooseInteger();    
	  insertInteger(&chosenPtr, value);
	  break;
	case 2:

	  if (!isEmpty(*chosenPtr)) {
	    value = chooseInteger();
	    deleteInteger(&chosenPtr, value);
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
      ListNodePtr mergedPtr = merge(&startPtr1, startPtr2);
      if (mergedPtr != NULL) {
	printList(mergedPtr);
      }
    }

    menuInstructions();
    scanf("%d", &menuChoice);
  }
}

void menuInstructions(void)
{
  printf("\n%s\n%s\n%s\n%s\n\n%s",
	 "1 - Select List 1.", "2 - Select List 2.",
	 "3 - Merge Lists.", "4 - Quit Program.", "> ");
}

void listInstructions(void)
{
  printf("\n%s\n%s\n%s\n%s\n\n%s",	 
	 "1 - Insert an integer.", "2 - Delete an integer.",
	 "3 - Print List.", "4 - Return to Main Menu.", "> ");
}

int chooseInteger(void)
{
  int integer;
  printf("\n%s\n\n%s", "Enter a integer:", "> ");
  scanf("\n%d", &integer);

  return integer;
}

void insertInteger(ListNodePtr **chosenPtr, int value)
{
  ListNodePtr newPtr = malloc(sizeof(ListNode));

  if (newPtr != NULL) {
    newPtr->integer = value;
    newPtr->nextPtr = NULL;

    ListNodePtr previousPtr = NULL;
    ListNodePtr currentPtr = **chosenPtr;
  
    while (currentPtr != NULL && value > currentPtr->integer) {

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
    printf("\n%d%s\n", value, " not inserted. No memory available.");
  }
}

void deleteInteger(ListNodePtr **chosenPtr, int value)
{
  if (value == ((**chosenPtr)->integer)) {
    ListNodePtr tempPtr = **chosenPtr;
    int tempValue = value;
    **chosenPtr = (**chosenPtr)->nextPtr;
    free(tempPtr);
    printf("\n%s%d%s\n", "Integer ", tempValue, " was deleted.");
  }
  else {
  
    ListNodePtr previousPtr = NULL;
    ListNodePtr currentPtr = **chosenPtr;

    if (currentPtr != NULL) {

      while (currentPtr != NULL && currentPtr->integer != value) {
	previousPtr = currentPtr;
	currentPtr = currentPtr->nextPtr;
      }

      if (currentPtr != NULL) {
	ListNodePtr tempPtr = currentPtr;
	char tempValue = value;	
	previousPtr->nextPtr = currentPtr->nextPtr;
	free(tempPtr);
	printf("\n%s%d%s\n", "Integer ", tempValue, " was deleted.");
      }
      else {
	printf("\n%s%d%s\n", "Integer ", value, " was not found in list.");
      }
    }
  }
}

void printList(ListNodePtr chosenPtr)
{
  if (chosenPtr != NULL) {

    puts("\nThe list is:\n");    
    while (chosenPtr != NULL) {

      printf("%d%s", chosenPtr->integer, " --> ");
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

ListNodePtr merge(ListNodePtr *startPtr1, ListNodePtr startPtr2)
{
  if (*startPtr1 == NULL) {

    if (startPtr2 == NULL) {
      puts("\nLists are empty.");
    }
    else {
      puts("\nList 1 is empty. List 2 is:");
      return startPtr2;
    }
  }
  else {

    if (startPtr2 == NULL) {
      puts("\nList 2 is empty. List 1 is:");
      return *startPtr1;
    }
    else {
      ListNodePtr currentPtr = startPtr2;

      while (currentPtr != NULL) {

	insertInteger(&startPtr1, currentPtr->integer);
	currentPtr = currentPtr->nextPtr;
      }
      return *startPtr1;  
    }
  }
  return NULL;
}
