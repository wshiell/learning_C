#include <stdio.h>

void isPrime(int candidate, int divisor);

int main(void)
{
  int candidate, divisor;

  do {  
  puts("Enter a number to test if it is prime (-1 to quit):");
  scanf("%d", &candidate);

  divisor = candidate;

  isPrime(candidate, divisor);
  puts("");
  
  } while (candidate != -1);
}

void isPrime(int candidate, int divisor)
{
  divisor = divisor - 1;
  
  if (divisor == 1) {
    printf("%d is prime.\n", candidate);    
  }
  else {

    if (candidate % divisor != 0) {
      isPrime(candidate, divisor);
    }
    else {
      
      if (candidate / divisor != 1) {
	 printf("%d is *not* prime.\n", candidate);    
      }
    }
  }
}
