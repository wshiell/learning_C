#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *nextPointer;
};

typedef struct node Node;
typedef Node *NodePtr;

int main(void)
{
  NodePtr nodePtr = NULL;
  Node node1 = {0, NULL};
  
  nodePtr = &node1;
    
  printf("Address 1 nodePtr: %p\n", &nodePtr);
  printf("Address 1 node1  : %p\n", &*nodePtr);

  nodePtr = *&node1.nextPointer;

  printf("Address 2 ThingPtr: %p\n", &nodePtr);
  printf("Address 2 NULL    : %p\n", &*nodePtr);  
  
}
