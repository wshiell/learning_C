#include <stdio.h>

int isPrime(int candidate, int divisor);

int main(void)
{
  int candidate = 2, divisor, limit, prime = 0, lineTest;

  puts("Enter a number to list all primes below it (-1 to quit):");
  scanf("%d", &limit);
  puts("");

  while (limit != -1) {
    prime = 0;
    
    while (candidate <= limit) {

      divisor = candidate;
      lineTest = prime;
      prime += isPrime(candidate, divisor);

      if ((prime % 10 == 0) && (prime != lineTest)) {
	puts("");
      }
      else {
	;
      }

      candidate++;
    }
    printf("\nNumber of primes: %d\n", prime);
    candidate = 2;
    puts("");
    puts("\nEnter a number to list all primes below it (-1 to quit):");
    scanf("%d", &limit);
    puts("");    
  }
}

int isPrime(int candidate, int divisor)
{
  divisor = divisor - 1;
  
  if (divisor == 1) {
    printf("%10d ", candidate % 3 - 1);
    return 1;
  }
  else {

    if (candidate % divisor != 0) {
      isPrime(candidate, divisor);
    }
    else {
      
      if (candidate / divisor != 1) {
	return 0;
      }
    }
  }
}
