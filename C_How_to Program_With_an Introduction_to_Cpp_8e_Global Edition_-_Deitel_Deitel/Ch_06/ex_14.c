#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 500
#define MAX 500

int main(void)
{

  srand(time(NULL));

  int a[SIZE];
  int b[SIZE];
  int c[SIZE * 2] = {0};

  // initialise array 'a'
  
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

  // initialise array 'b'
  
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
  
  // Combine arrays 'a' and 'b' into array 'c'

  for (int count = 0; count < SIZE; count++) {
    c[count] = a[count];
  }

  for (int count = SIZE; count < SIZE * 2; count++) {
    c[count] = b[count - SIZE];
  }

  // Print unsorted array 'c'

  puts("\nArray 'c' (unsorted)\n");
  
  for (int count = 0; count < SIZE * 2; count++) {
    printf("%5d ", c[count]);

    if ((count + 1) % 20 == 0) {
      puts("");
    }
  }
  
  puts("");

  // Sort array 'c'

  int hold;

  for (int count1 = 0; count1 < SIZE * 2; count1++) {

    for (int count2 = count1 + 1; count2 < SIZE * 2; count2++) {

      if (c[count1] >= c[count2]) {
	hold = c[count2];
	c[count2] = c[count1];
	c[count1] = hold;

      }
    }
  }

  // Print sorted array 'c'

  puts("\nArray 'c' (sorted)\n");
  
  for (int count = 0; count < SIZE * 2; count++) {
    printf("%5d ", c[count]);

    if ((count + 1) % 20 == 0) {
      puts("");
    }
  }
  
  puts("");

  // Eliminate non unique elements

  int unique = 0;

  for (int count = 0; count < SIZE * 2; count++) {

    if (count == 0) {
      unique++;
     }
    else {

      if (c[count - 1] != c[count]) {
	unique++;
      }
    }
  }

  // Initialise array 'd'

  int d[unique];
  unique = 0;
  
  // Populate array 'd' with unique elements of array 'c'
  
  for (int count = 0; count < SIZE * 2; count++) {

    if (count == 0) {
      d[unique] = c[count];
      unique++;
    }
    else {

      if (c[count - 1] != c[count]) {
	d[unique] = c[count];
	unique++;
      }
    }
  }

  // Print array 'd'

  puts("\nArray 'd'\n");
  
  for (int count = 0; count < unique; count++) {
    printf("%5d ", d[count]);

    if ((count + 1) % 20 == 0) {
      puts("");
    }
  }

  printf("\n\nTotal elements in 'c': %5d\n", SIZE * 2);  
  printf("\nUnique elements in 'c': %5d\n", unique);

  puts("");
}
