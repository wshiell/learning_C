#include <stdio.h>

int main(void)
{
  int x, y;
  
  printf("%s\n\n%s", "Enter two integers seperated by a space:", "> ");
  scanf("%i%d", &x, &y);
  printf("\n%d %d\n", x, y);
}
