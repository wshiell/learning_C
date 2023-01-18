#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
#define MAX 10000

int main(void) {

  srand(time(NULL));

  int array[SIZE];
  int gap = 0;

  for (int count = 0; count < SIZE; count++) {

    array[count] = rand() % MAX;
  }

  puts("Unsorted array");

  for (int count = 0; count < SIZE; count++) {
    printf("%d\t", array[count]);

    if ((count + 1) % 10 == 0) {
      puts("");
    }
  }

  puts("");
  
  for (int count1 = 0; count1 < SIZE; count1++) {
      int smallest = MAX;
      int hold;

      for (int count2 = count1; count2 < SIZE; count2++) {

      if (array[count2] <= array[count1]) {

      	hold = array[count1];
      	array[count1] = array[count2];
      	array[count2] = hold;
      }
    }
  }

  puts("Sorted array");

  for (int count = 0; count < SIZE; count++) {
    printf("%d\t", array[count]);

    if ((count + 1) % 10 == 0) {
      puts("");
    }
  }
  puts("");
}
