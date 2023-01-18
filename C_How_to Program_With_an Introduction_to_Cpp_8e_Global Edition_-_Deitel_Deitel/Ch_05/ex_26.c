#include <stdio.h>

void isPerfect(int number);
void printDivisors(int number);
void printPerfect(int number);
		  
int main(void)
{
  int limit;

  puts("Enter upper limit (-1 to quit):");
  scanf("%d", &limit);

  while (limit != -1) {
    printf("%-20s%s\n", "Perfect Number", "Factors");
    puts("");
  
    for (int count = 1; count <= limit; count++) {
      isPerfect(count);
    }
    printf("%-20s", "Perfect Numbers:");
    
    for (int count = 1; count <= limit; count++) {
      printPerfect(count);
    }
    
    puts("\n\nEnter upper limit (-1 to quit):");
    scanf("%d", &limit);
  }
}


void isPerfect(int number)
{
  int perfect = 0;

  for (int divisor = 1; divisor <= (number / 2); divisor++) {

    if (number % divisor == 0) {
     perfect += divisor;
    }
  }
  
  if (number == perfect) {
    printf("%-20d", number);
    printDivisors(number);
    puts("");
  }
 }

void printDivisors(int number)
{
  int count = 1;

  for (int divisor = 1; divisor <= (number / 2); divisor++) {
    
    if (number % divisor == 0) {

      if (count % 5 == 0) {
        puts("");
	printf("%-20s", "");
      }

      printf("%-10d ", divisor);
      count++;
    }
  }
  puts("");
}

void printPerfect(int number)
{
  int perfect = 0;

  for (int divisor = 1; divisor <= (number / 2); divisor++) {

    if (number % divisor == 0) {
     perfect += divisor;
    }
  }
  
  if (number == perfect) {
    printf("%-10d", number);
  }
}
