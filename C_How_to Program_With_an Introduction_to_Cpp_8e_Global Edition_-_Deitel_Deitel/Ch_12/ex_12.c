#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

struct stackNode {
  char data;
  struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void convertToPostfix(StackNodePtr *topPtr, char infix[], char postfix[]);
int isOperator(char c);
int precedence(char operator1, char operator2);
void push(StackNodePtr *topPtr, char value);
char pop(StackNodePtr *topPtr);
char stackTop(StackNodePtr topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr topPtr);

int main(void)
{
  StackNodePtr topPtr = NULL;
  char infix[SIZE] = "", postfix[SIZE] = "";

  convertToPostfix(&topPtr, infix, postfix);
}

void convertToPostfix(StackNodePtr *topPtr, char infix[], char postfix[])
{
  int length;
  int i = 0, j = 0;

  puts("Enter a valid arithmetic expression:");
  fgets(infix, SIZE, stdin);

  length = strlen(infix);  
  infix[length] = '\0';

  push(topPtr, '(');
  infix[length - 1] = ')';
  
  while (!isEmpty(*topPtr)) {

  }

  puts(postfix);
}

int isOperator(char c)
{
  if (c == 37 || c == 42 || c == 43 || c == 45 || c == 47 || c == 94) {
    return 1;
  }
  else {
    return 0;
  }
}

int precedence(char operator1, char operator2)
{
  if (operator1 < operator2) {
    return -1;
  }
  else if (operator1 == operator2) {
    return 0;
  }
  else {
    return 1;
  }
}

void push(StackNodePtr *topPtr, char value)
{
  StackNodePtr newPtr = malloc(sizeof(StackNode));

  if (newPtr != NULL) {

    newPtr->data = value;
    *topPtr = newPtr;
  }
  else {
    puts("Character not added. No memory available.");
  }
}

char pop(StackNodePtr *topPtr)
{
  if (*topPtr != NULL) {

    StackNodePtr tempPtr = *topPtr;
    char c = tempPtr->data;
    *topPtr = tempPtr->nextPtr;
    free(tempPtr);
    return c;
  }
  else {
    return '\0';
  }
}

char stackTop(StackNodePtr topPtr)
{
  return topPtr->data;
}

int isEmpty(StackNodePtr topPtr)
{
  return topPtr == NULL;
}

void printStack(StackNodePtr topPtr)
{
  while (topPtr != NULL) {
    printf("%c", topPtr->data);
    topPtr = topPtr->nextPtr;
  }
}
