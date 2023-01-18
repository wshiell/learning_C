#include <stdio.h>
#define SIZE 100

int arrayStrLen(char *string);
int pointerStrLen(char *string);

int main(void)
{
  char string[SIZE];
  
  printf("\n%s\n\n%s", "Enter string:", "> ");
  fgets(string, SIZE, stdin);

  printf("\n%s\n%s%d\n", "arrayStrLen(string):", "String length is: ",
	 arrayStrLen(string));
  printf("\n%s\n%s%d\n", "arrayStrLen(string):", "String length is: ",
	 pointerStrLen(string));  
}

int arrayStrLen(char *string)
{
  int length = 0;
  
  for (int i = 0; i < SIZE; i++) {

    if (string[i] == '\n') {
      length = i;
    }
  }
  return length;
}


int pointerStrLen(char *string)
{
  int length = 0;
  char *stringPtr;

  stringPtr = &*string;
  
  for (; *stringPtr != '\n'; stringPtr++) {

    length++;
  }
  return length;  
}
