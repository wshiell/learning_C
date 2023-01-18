#include <stdio.h>

int main(void)
{
  unsigned int counter = 1;
  
  while (counter <=5) {
    unsigned int number;
    puts("Enter a number:");
    scanf("%u", &number);
    
    for (unsigned int tally = 1; tally <= number; tally++) {
      printf("*");
    }
    counter++;
    puts("");
  }
}
