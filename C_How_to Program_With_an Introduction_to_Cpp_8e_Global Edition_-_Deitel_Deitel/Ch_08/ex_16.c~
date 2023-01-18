#include <stdio.h>
#include <string.h>
#define SIZE 100

int main(void)
{
  int count = 0;
  char mainString[SIZE], searchString[SIZE], *searchPtr;
  
  puts("Enter a string:");
  printf("\n%s", "> ");
  fgets(mainString, SIZE, stdin);

  while (mainString[count] != '\0') {
    count++;
  }

  mainString[count] = '\0';

  puts("\nEnter a string:");
  printf("\n%s", "> ");
  fgets(searchString, SIZE / 2, stdin);

  while (searchString[count] != '\0') {
    count++;
  }

  mainString[count - 1] = '\0';
  
  searchPtr = strstr(mainString, searchString);

  if (searchPtr == NULL) {
    printf("\n%s\n", "Search failed.");        
  }
  else {

    while (searchPtr != NULL) {
      printf("\n%s\n", searchPtr);
      searchPtr = strstr(searchPtr + 1, searchString);
    }
  }
}
