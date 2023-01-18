#include <stdio.h>
#include <string.h>

#define SIZE 100
#define PRINT puts(string)

int main(void)
{
  char string[SIZE];
  puts("Enter a string:");
  fgets(string, SIZE, stdin);
  int length = strlen(string);
  string[length - 1] = '\0';
  PRINT;
}
