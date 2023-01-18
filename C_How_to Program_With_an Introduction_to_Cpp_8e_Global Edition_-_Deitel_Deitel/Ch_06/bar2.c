#include <stdio.h>

int main(void)
{
  char *string = "lol";

  for (size_t i = 0; i < 5; i++) {
    printf("%c", string[i]);
  }
  puts("");
  printf("%c\n", '\0');
}
