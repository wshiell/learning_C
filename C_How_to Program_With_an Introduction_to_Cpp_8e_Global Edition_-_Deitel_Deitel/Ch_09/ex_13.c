#include <stdio.h>

int main(void)
{
  int a;
  printf("\n%s\n\n%s", "Enter an integer using conversion specifier \'d\':", "> ");
  scanf("%d", &a);
  printf("\n%s%d\n\n", "The integer is: ", a);

  printf("\n%s\n\n%s", "Enter an integer using conversion specifier \'i\':", "> ");
  scanf("%i", &a);
  printf("\n%s%d\n\n", "The integer is: ", a);

  printf("\n%s\n\n%s", "Enter an integer using conversion specifier \'u\':", "> ");
  scanf("%u", &a);
  printf("\n%s%d\n\n", "The integer is: ", a);

  printf("\n%s\n\n%s", "Enter an integer using conversion specifier \'o\':", "> ");
  scanf("%o", &a);
  printf("\n%s%d\n\n", "The integer is: ", a);

  printf("\n%s\n\n%s", "Enter an integer using conversion specifier \'x\':", "> ");
  scanf("%x", &a);
  printf("\n%s%d\n\n", "The integer is: ", a);

  printf("\n%s\n\n%s", "Enter an integer using conversion specifier \'h\':", "> ");
  scanf("%hd", &a);
  printf("\n%s%d\n\n", "The integer is: ", a);

  printf("\n%s\n\n%s", "Enter an integer using conversion specifier \'l\':", "> ");
  scanf("%ld", &a);
  printf("\n%s%d\n\n", "The integer is: ", a);

  printf("\n%s\n\n%s", "Enter an integer using conversion specifier \'ll\':", "> ");
  scanf("%lld", &a);
  printf("\n%s%d\n\n", "The integer is: ", a);
}
