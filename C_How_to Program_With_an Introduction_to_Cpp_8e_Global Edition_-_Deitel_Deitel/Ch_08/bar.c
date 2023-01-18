#include <stdio.h>
/* #define SIZE 100 */

void strToUL(char *string, char* *Ptr);

int main(void)
{
  char string[] = "Hiya";
  char *unsignedPtr;

  /* puts("\nEnter a string containing an integer or a double:"); */
  /* printf("\n%s", "> "); */
  
  fgets(string, 6, stdin);
  strToUL(string, &unsignedPtr);
  printf("\n%s\n", unsignedPtr);
}

void strToUL(char *string, char** Ptr)
{
  *Ptr = string;
}
