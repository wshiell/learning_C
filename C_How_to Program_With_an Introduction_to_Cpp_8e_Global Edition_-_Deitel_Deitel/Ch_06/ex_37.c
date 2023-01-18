// ****************************************
//
// Chapter 6, ex_35.c
//
// ****************************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

int recursiveMinimum(int array[], int size);

int main(void)
{

  srand(time(NULL));

  int result;
  int size = SIZE;
  int array[size];

  for (int count = 0; count < size; count++) {
    array[count] = rand() % size;
  }

  for (int count = 0; count < size; count++) {
    printf("%3d", array[count]);
  }
  puts("");
  
  result = recursiveMinimum(array, size);

  printf("Minimum: %d\n", result);
}

int recursiveMinimum(int array[], int size)
/* { */
/* if (size == 0) { */
/*   printf("Minimum value: %d\n", min); */
/* } */
/* else { */

/*   if (array[size] < min) { */
/*     min = array[size]; */
/*   } */
/*   recursiveMinimum(array, size - 1, min); */
/* } */
{
  int min = array[0];

  if (size == 1) {
    return array[0];
  }
  else if (size == 2) {

    if (min < array[size - 1]) {

      if (min < array[size - 2]) {
	return min;
      }
    }
    else if (array[size - 1] < array[size - 2]) {
      return array[size - 1];
    }
    else {
      return array[size - 2];
    }
  }
  else if (min < array[size - 1]) {

    if (min < array[size - 2]) {

      if (min < array[size - 3]) {
	return min;
      }
    }
    else if (array[size - 2] < array[size - 3]) {
      return array[size - 2];
    }
    else {
      return array[size - 3];
    }
  }
  else if (array[size - 1] < array[size - 2]) {

    if (array[size - 1] < array[size - 3]) {
      return array[size - 1];
    }
    else {
      return array[size - 3];
    }
  }
  else if (array[size - 2] < array[size - 3]){
    return array[size - 2];
  }
  else {
    return array[size - 3] ;
  }
}
