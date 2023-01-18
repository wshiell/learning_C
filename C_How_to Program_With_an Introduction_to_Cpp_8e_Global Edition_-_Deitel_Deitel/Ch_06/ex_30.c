// ****************************************
//
// Chapter 6, ex_30.c
//
// ****************************************

#include <stdio.h>
#include <time.h>

void initialiseArray(int array[], int SIZE);
void sieve(int array[], int SIZE);
void printArray(int array[], double time_spent, int SIZE);
void primeList(int primes[], int eratosthenes[], int SIZE);
void sortArray(int array[], int SIZE);

int main(void)
{
  int SIZE;
  
  puts("Enter number to list all primes below (and including) it:");
  puts("(Type -1 to end)");
  scanf("%d", &SIZE);

  while(SIZE != -1) {
  
    clock_t begin = clock();
  
    int eratosthenes[SIZE];
    int primes[SIZE];

    initialiseArray(primes, SIZE); // Initialise array 'primes' to 1
    initialiseArray(eratosthenes, SIZE); // Initialise array 'eratosthenes' to 1
    sieve(eratosthenes, SIZE); // Eliminate all elements whose indices are not prime
    primeList(primes, eratosthenes, SIZE); // Populate array 'primes' with primes
    sortArray(primes, SIZE); // Move all zeroes to the end of the array

    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
  
    printArray(primes, time_spent, SIZE); // Print the array of prime numbers

    puts("Enter number to list all primes below (and including) it:");
    puts("(Type -1 to end)");
    scanf("%d", &SIZE);    
  }
}

void initialiseArray(int array[], int SIZE)
{
  for (int count = 0; count < SIZE; count++) {

    array[count] = 1;
  }
}

void sieve(int array[], int SIZE)
{
  for (int index1 = 1; index1 <= SIZE; index1++) {

    if (index1 == 1) {
      array[index1] = 0;
    }
    else {

      for (int index2 = index1 + 1; index2 < SIZE; index2++) {

	if (index2 % index1 == 0) {
	  array[index2] = 0;
	}
      }
    }
  }  
}

void printArray(int array[], double time_spent, int SIZE)
{
  int tally = 0;

  printf("\n Primes less than or equal to %d\n\n", SIZE);
  
  for (int count = 0; count < SIZE; count++) {

    if (array[count] != 1 && array[count] != 0) {
      printf("%10d", array[count]);
      tally++;
    }
    if (tally % 5 == 0 && array[count] != 0 && array[count] != 1) {
      puts("");
    }
  }
  printf("\n\nTotal run time: %.2lf seconds\n\n", time_spent);
}

void primeList(int primes[], int eratosthenes[], int SIZE)
{
  for (int count = 0; count < SIZE; count++) {
    
    if (eratosthenes[count] != 0) {
      primes[count] = count;
    }
  }
}

void sortArray(int array[], int SIZE)
{
  for (int count1 = 0; count1 < SIZE - 1; count1++) {

    for (int count2 = count1; count2 >= 0; count2--) {

      int temp = array[count2];

      if (array[count2] > array[count2 + 1]) {
	array[count2] = array[count2 + 1];
	array[count2 + 1] = temp;
      }
    }
  }
}
