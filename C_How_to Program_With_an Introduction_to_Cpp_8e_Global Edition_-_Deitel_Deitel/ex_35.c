#include <stdio.h>

int main(void)
{
  unsigned int x;

  for (x = 1; x <= 10; ++x) {

    if (x == 5) {
      x = 11;
      if (x > 10) {
	puts("\nReplacing the value of x breaks out of the loop,"
             " replacing the break statement");
	printf("%s", "x = ");
      }
    }

    printf("%u", x);
  }

  printf("\nBroke out of loop at x == %u\n", x);
}
