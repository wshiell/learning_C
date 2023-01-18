#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4
#define LIMIT 4

struct listNode {
  int integer;
  struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void generateNumbers(int randomList[SIZE]);
void insertInteger(ListNodePtr *chosenPtr, int value);
void printList(ListNodePtr chosenPtr);
void calculations(int randomList[SIZE]);

int main(void)
{
  srand(time(NULL));

  int randomList[SIZE];
  ListNodePtr chosenPtr = NULL;

  generateNumbers(randomList);

  for (size_t i = 0; i < SIZE; ++i) {
  
    insertInteger(&chosenPtr, randomList[i]);
  }
  printList(chosenPtr);
  calculations(randomList);
}

void insertInteger(ListNodePtr *chosenPtr, int value)
{
  ListNodePtr newPtr = malloc(sizeof(ListNode));

  if (newPtr != NULL) {
    newPtr->integer = value;
    newPtr->nextPtr = NULL;

    ListNodePtr previousPtr = NULL;
    ListNodePtr currentPtr = *chosenPtr;
  
    while (currentPtr != NULL && value > currentPtr->integer) {

      previousPtr = currentPtr;
      currentPtr = currentPtr->nextPtr;
    }

    if (previousPtr == NULL) {
      newPtr->nextPtr = *chosenPtr;
      *chosenPtr = newPtr;
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

void printList(ListNodePtr chosenPtr)
{
  int count = 0;
    
  while (chosenPtr != NULL) {

    printf("%3d", chosenPtr->integer);
    chosenPtr = chosenPtr->nextPtr;

    if ((count + 1) % 10 == 0) {
      puts("");
    }
    count++;
  }
}

void generateNumbers(int randomList[SIZE])
{
  for (size_t i = 0; i < SIZE; ++i) {
    randomList[i] = rand() % LIMIT;
  }
}

void calculations(int randomList[SIZE])
{
  int total = 0, zeroCount = 0;
  double average;

  for (size_t i = 0; i < SIZE; i++) {
    total += randomList[i];

    if (randomList[i] == 0) {
      zeroCount++;
    }
  }

  average = (float) total / (SIZE - zeroCount);
  printf("\n%s%d\n", "Sum of the list of random integers: ", total);
  printf("%s%.2lf\n", "Average of the list of random integers: ", average);
}
