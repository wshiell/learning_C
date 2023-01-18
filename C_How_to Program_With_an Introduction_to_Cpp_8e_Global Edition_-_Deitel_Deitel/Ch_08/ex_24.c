#include <stdio.h>
#include <string.h>

#define SIZE 100

int main(void)
{
  int length;
  char string[SIZE];
  
  printf("\n%s\n\n%s", "Enter a string (type 'q' to quit):", "> ");
  fgets(string, SIZE, stdin);
  length = strlen(string);
  
  while (string[0] != 'q') {
    
    if (string[length - 2] == 'n' && string[length - 3] == 'o' &&
	string[length - 4] == 'i' && string[length - 5] == 't') {
      printf("\n%s%s", "String: ", string);
    }
    else {
      printf("\n%s\n", "String does not end with 'tion'.");
    }
    printf("\n%s\n\n%s", "Enter a string (type 'q' to quit):", "> ");
    fgets(string, SIZE, stdin);
    length = strlen(string);
  }
}
