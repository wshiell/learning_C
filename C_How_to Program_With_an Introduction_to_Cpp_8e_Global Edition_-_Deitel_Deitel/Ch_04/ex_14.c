#include <stdio.h>

int main(void)
{

  unsigned int factorial = 1;

  printf("%-10s%-10s\n\n", "n", "n!");
  
  for (unsigned int number = 1; number <= 5; number++) {

    if ((number == 1) || (number == 0)) {
      factorial = 1;
    }
    else {

      for (unsigned int counter = 1; counter < number; counter++) {
 	factorial *= (counter + 1);
      }
    }
    printf("%-10u%-10u\n", number, factorial);
    factorial = 1;
  }
}
