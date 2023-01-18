#include <stdio.h>

int main(void)
{
  unsigned int number;
  unsigned int sum = 0;
  float average = 0;
  
  puts("Enter a positive number:");
  scanf("%u", &number);

  for ( unsigned int counter = 1; counter <= number; counter++) {
    sum += counter * counter;
  }
  
  if ( number > 0 ) {
    average = (float) sum / number;
    printf("Sum: %u\n", sum);
    printf("The average of all squares from 1 - %u: %.2f\n", number, average);
  }
  else {
    puts("Invalid number entered.");
  }
}
