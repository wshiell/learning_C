#include <stdio.h>
#define SIZE 100

int main(void)
{
  char string[SIZE];
  
  printf("\n%s\n\n%s", "Enter a string (type 'q' to quit):", "> ");
  fgets(string, SIZE, stdin);

  while (string[0] != 'q') {
    
    if(string[0] == 'T' && string[1] == 'h') {
      printf("\n%s%s", "String: ", string);
    }
    else {
      printf("\n%s\n", "String does not begin with 'Th'.");
    }
    printf("\n%s\n\n%s", "Enter a string (type 'q' to quit):", "> ");
      fgets(string, SIZE, stdin);    
  }
}
