// ****************************************
//
// Chapter 6, ex_28.c
//
// ****************************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void initialiseArray(int array[SIZE]);
void printArray(int array[], int size);
void sortArray(int array[SIZE]);
void reduceArray(int array[SIZE]);
int numberElements(int array[]);
void finalArray(int array[SIZE], int final[], int size);

int main(void)
{
  srand(time(NULL));

  int size;
  int duplicates[SIZE];
  int final[size];

  initialiseArray(duplicates);

  puts("\nArray 'duplicates (not sorted)'\n");
  printArray(duplicates, SIZE);

  sortArray(duplicates);
  reduceArray(duplicates);
  sortArray(duplicates);

  puts("\n\nArray 'duplicates (sorted, not reduced)'\n");
  printArray(duplicates, SIZE);

  size = numberElements(duplicates);

  finalArray(duplicates, final, size);

  puts("\n\nArray 'duplicates (sorted, reduced)'\n");
  printArray(final, size);
  puts("\n");
}

void initialiseArray(int array[])
{
  for (int count = 0; count < 20; count++) {

    array[count] = 1 + rand() % 20;
  }
}

void sortArray(int array[SIZE])
{
  for (int counter = 0; counter < SIZE - 1; counter++) {

    for (int count = counter; count >= 0; count--) {

      int temp;

      temp = array[count];

      if (array[count + 1] > array[count]) {
	array[count] = array[count + 1];
	array[count + 1] = temp;
      }
    }
  }
}

void reduceArray(int array[])
{

  for (int count1 = 0; count1 < SIZE; count1++) {

    for (int count2 = 0; count2 < count1; count2++) {

      if (array[count2] == array[count2 + 1]) {
	array[count2] = 0;
      }
    }
  }
}

int numberElements(int array[SIZE])
{
  int size = 0;
  
  for (int count = 0; count < SIZE; count++) {

    if (array[count] == 0) {
      break;
    }
    else {
      size++;
    }
  }
  return size;
}

void finalArray(int array[SIZE], int final[], int size)
{
  for (int count = 0; count < SIZE; count++) {

    final[count] = array[count];

    if (count == size) {
      break;
    }
  }
}

void printArray(int array[], int size)
{
  for (int count = 0; count < size; count++) {

    printf("%3d", array[count]);
  }
}
