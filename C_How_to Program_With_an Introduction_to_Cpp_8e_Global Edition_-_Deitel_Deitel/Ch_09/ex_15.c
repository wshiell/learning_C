#include <stdio.h>

int main(void)
{
  char string[5];
  
  printf("\n%s\n\n%s", "Enter \'suzy\':", "> ");
  scanf("%s", string);
  printf("%s\n", string);

  printf("\n%s\n\n%s", "Enter \'\'suzy\'\':", "> ");
  scanf("%s", string);
  printf("%s\n", string);

  printf("\n%s\n\n%s", "Enter \'\"suzy\"\':", "> ");
  scanf("%s", string);  
  printf("%s\n", string);
}
