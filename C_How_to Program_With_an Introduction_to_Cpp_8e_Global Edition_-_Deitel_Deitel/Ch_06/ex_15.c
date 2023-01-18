#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 800
#define MAX 1000

int main(void)
{

  srand(time(NULL));

  int a[SIZE];
  int b[SIZE];

  // Initialise array 'a'
  
  for (int count = 0; count < SIZE; count++) {
    a[count] = rand() % MAX;
  }

  // Print array 'a'
  
  puts("\nArray 'a'\n");
  
  for (int count = 0; count < SIZE; count++) {
    printf("%5d ", a[count]);

    if ((count + 1) % 20 == 0) {
      puts("");
    }
  }

  // Initialise array 'b'
  
  for (int count = 0; count < SIZE; count++) {
    b[count] = rand() % MAX;
  }

  // Print array 'b'
  
  puts("\n\nArray 'b'\n");
  
  for (int count = 0; count < SIZE; count++) {
    printf("%5d ", b[count]);

    if ((count + 1) % 20 == 0) {
      puts("");
    }
  }

  puts("");
  
  /* // Combine arrays 'a' and 'b' into array 'c' */

  /* for (int count = 0; count < SIZE; count++) { */
  /*   c[count] = a[count]; */
  /* } */

  /* for (int count = SIZE; count < SIZE * 2; count++) { */
  /*   c[count] = b[count - SIZE]; */
  /* } */

  // Print unsorted array 'c'

  /* puts("\nArray 'c' (unsorted)\n"); */
  
  /* for (int count = 0; count < SIZE * 2; count++) { */
  /*   printf("%5d ", c[count]); */

  /*   if ((count + 1) % 20 == 0) { */
  /*     puts(""); */
  /*   } */
  /* } */
  
  /* puts(""); */

  // Sort array 'a'

  int hold;

  for (int count1 = 0; count1 < SIZE; count1++) {

    for (int count2 = count1 + 1; count2 < SIZE; count2++) {

      if (a[count1] >= a[count2]) {
	hold = a[count2];
	a[count2] = a[count1];
	a[count1] = hold;

      }
    }
  }

  // Sort array 'b'


  for (int count1 = 0; count1 < SIZE; count1++) {

    for (int count2 = count1 + 1; count2 < SIZE; count2++) {

      if (b[count1] >= b[count2]) {
	hold = b[count2];
	b[count2] = b[count1];
	b[count1] = hold;

      }
    }
  }

  // Print sorted array 'a'

  puts("\nArray 'a' (sorted)\n");
  
  for (int count = 0; count < SIZE; count++) {
    printf("%5d ", a[count]);

    if ((count + 1) % 20 == 0) {
      puts("");
    }
  }
  
  puts("");

  // Print sorted array 'b'

  puts("\nArray 'b' (sorted)\n");
  
  for (int count = 0; count < SIZE; count++) {
    printf("%5d ", b[count]);

    if ((count + 1) % 20 == 0) {
      puts("");
    }
  }
  
  puts("");

  // Count unique elements in array 'a'

  int unique_A = 0;

  for (int count = 0; count < SIZE; count++) {

    if (count == 0) {
      unique_A++;
     }
    else {

      if (a[count - 1] != a[count]) {
	unique_A++;
      }
    }
  }

  // Count unique elements in array 'b'

  int unique_B = 0;

  for (int count = 0; count < SIZE; count++) {

    if (count == 0) {
      unique_B++;
     }
    else {

      if (b[count - 1] != b[count]) {
	unique_B++;
      }
    }
  }

  // Initialise 'unique' arrays 'A' and 'B'

  int A[unique_A];
  int B[unique_B];

  unique_A = 0, unique_B = 0;
  
  // Populate array 'A' with unique elements of array 'a'
  
  for (int count = 0; count < SIZE; count++) {

    if (count == 0) {
      A[unique_A] = a[count];
      unique_A++;
    }
    else {

      if (a[count - 1] != a[count]) {
  	A[unique_A] = a[count];
  	unique_A++;
      }
    }
  }

  // Populate array 'B' with unique elements of array 'b'
  
  for (int count = 0; count < SIZE; count++) {

    if (count == 0) {
      B[unique_B] = b[count];
      unique_B++;
    }
    else {

      if (b[count - 1] != b[count]) {
  	B[unique_B] = b[count];
  	unique_B++;
      }
    }
  }

  // Print array 'A'

  puts("\nArray 'A' (unique, sorted 'a')\n");
  
  for (int count = 0; count < unique_A; count++) {
    printf("%5d ", A[count]);

    if ((count + 1) % 20 == 0) {
      puts("");
    }
  }

  puts("");
  
  // Print array 'B'

  puts("\nArray 'B' (unique, sorted 'a')\n");
  
  for (int count = 0; count < unique_B; count++) {
    printf("%5d ", B[count]);

    if ((count + 1) % 20 == 0) {
      puts("");
    }
  }

  puts("");

  // Count unique elements in array 'c'

  int unique_C = 0;

  for (int count1 = 0; count1 < unique_A; count1++) {

    for (int count2 = 0; count2 < unique_B; count2++) {

      if (B[count2] == A[count1]) {
      	unique_C++;
      	break;
      }
    }
  }

  // Initialise array 'c' (array containing elements common to 'a' and 'b')

  int c[unique_C];
  unique_C = 0;
  
  // Populate array 'c'

  for (int count1 = 0; count1 < unique_A; count1++) {

    for (int count2 = 0; count2 < unique_B; count2++) {
  
      if (B[count2] == A[count1]) {
	c[unique_C] = B[count2];
	unique_C++;
     	break;
      }
    }
  }

  // Print array 'c'

  puts("\nArray 'C' (intersection of 'A' and 'B')\n");
  
  for (int count = 0; count < unique_C; count++) {
    printf("%5d ", c[count]);

    if ((count + 1) % 20 == 0) {
      puts("");
    }
  }

  // Summary
  
  printf("\n\nElements in original sets 'a' and 'b':  %5d\n", SIZE);
  
  printf("\nUnique elements in 'a': %5d\n", unique_A);
  printf("\nUnique elements in 'b': %5d\n", unique_B);
  printf("\nUnique elements in 'c': %5d\n", unique_C);

  puts("");
}
