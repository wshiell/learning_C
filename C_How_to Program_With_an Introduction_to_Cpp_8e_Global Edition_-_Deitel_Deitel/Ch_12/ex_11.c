#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 1000

struct listNode {
  char data;
  struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void enterSentence(char value[SIZE]);
void list(ListNodePtr *listPtr, char * value);
void push(ListNodePtr *stackPtr, char * value);
void isPalindrome(ListNodePtr *listPtr, ListNodePtr *stackPtr);

int main(void)
{
  char value[SIZE];
  ListNodePtr listPtr = NULL, stackPtr = NULL;

  puts("\n*** Palindrome Testing Program ***\n");

  enterSentence(value);
  list(&listPtr, value);
  push(&stackPtr, value);
  isPalindrome(&listPtr, &stackPtr);
}

void enterSentence(char value[SIZE])
{
  char c;
  int i = 0;

  printf("\n%s\n\n%s", "Enter a sentence:", "> ");
  
  while ((c = getchar()) != '\n') {

    if (isalnum(c)) {
      c = tolower(c);
      value[i++] = c;
    }
  }

  value[i] = '\0';
}

void list(ListNodePtr *listPtr, char * value)
{
  int i = 0, length = strlen(value);
  char c;
  
  while (i < length) {

    c = value[i++];
    
    ListNodePtr newPtr = malloc(sizeof(ListNode));

    if (newPtr != NULL) {
      newPtr->data = c;
      newPtr->nextPtr = NULL;

      ListNodePtr previousPtr = NULL;
      ListNodePtr currentPtr = *listPtr;
  
      while (currentPtr != NULL) {

	previousPtr = currentPtr;
	currentPtr = currentPtr->nextPtr;
      }

      if (previousPtr == NULL) {
	newPtr->nextPtr = *listPtr;
	*listPtr = newPtr;
      }
      else {
	previousPtr->nextPtr = newPtr;
	newPtr->nextPtr = currentPtr;
      }
    }
    else {
      printf("\n%c%s\n", c, " not inserted. No memory available.");
    }
  }
}

void push(ListNodePtr *stackPtr, char * value)
{
  int i = 0, length;
  char c;

  length = strlen(value);
  
  while (i < length) {

    c = value[i++];
    ListNodePtr newPtr = malloc(sizeof(ListNode));

    if (newPtr != NULL) {
      newPtr->data = c;
      newPtr->nextPtr = *stackPtr;
      *stackPtr = newPtr;
    }
    else {
      printf("\n%s%s\n", value, " not inserted. No memory available.");
    }
  }
}

void isPalindrome(ListNodePtr *listPtr, ListNodePtr *stackPtr)
{
  int error = 0;
  
  while (*listPtr != NULL && *stackPtr != NULL) {

    if ((*listPtr)->data != (*stackPtr)->data) {
      puts("\nSentence is *NOT* a palindrome.\n");
      error++;
      break;
    }
    
    *listPtr = (*listPtr)->nextPtr;
    *stackPtr = (*stackPtr)->nextPtr;
  }

  if (error == 0) {
    puts("\nSentences *IS* a palindrome.\n");
  }
}
