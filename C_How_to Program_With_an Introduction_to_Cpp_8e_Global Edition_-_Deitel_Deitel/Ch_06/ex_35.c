// ****************************************
//
// Chapter 6, ex_35.c
//
// ****************************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void printArray(const int array[], int arraySize);

int main(void)
{
  srand(time(NULL));
  int array[SIZE];
  
  for (int count = 0; count < SIZE; count++) {
    array[count] = rand() % 100;    
  }

  puts("");

  printArray(array, SIZE);
  puts("");
}

void printArray(const int array[], int arraySize)
{
  if (0 < arraySize) {
    printf("%3d", array[SIZE - arraySize]);    
    printArray(array, arraySize - 1);
  }
}
