#include <stdio.h>

int main(void)
{
  char *word;
  int a;
  
  printf("%s\n", "Enter something:");
  scanf("%s%n", word, &a);

  printf("%d\n", a);
}
