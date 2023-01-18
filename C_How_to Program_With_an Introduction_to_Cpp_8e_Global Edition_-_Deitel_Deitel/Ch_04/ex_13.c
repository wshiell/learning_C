#include <stdio.h>

int main(void)
{
  unsigned int number;
  unsigned int  sum = 0, sumSquare = 0, sumCube = 0;

  puts("Enter a natural number:");
  scanf("%u", &number);

  for (unsigned int counter = 1; counter <= number; counter++) {

    sum += counter;
    sumSquare += counter * counter;
    sumCube += counter * counter * counter;
  }
  printf("Sum:\t%u\nSum of Squares:\t%u\nSum of Cubes:\t%u\n",
	 sum, sumSquare, sumCube);
  puts("");
}
