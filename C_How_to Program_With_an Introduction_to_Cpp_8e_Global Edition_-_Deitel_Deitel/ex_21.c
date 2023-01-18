#include <stdio.h>

int main(void)
{
  for (unsigned int counter = 0; counter <= 127; counter++) {
    printf("%c\t", counter);
    if ((counter + 1) % 10 == 0) {
      puts("");
    }
  }
  puts("");
  printf("Character: %c", 0);
  puts("");
}
