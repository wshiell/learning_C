#include <stdio.h>
#include <string.h>
#define SIZE 100
#define LIMIT 6

void enterString(void);
int searchStrings(char *string, char *search);

int main(void)
{
  enterString();
}

void enterString(void)
{
  int count = 0;
  int sum = 0;
  char search[SIZE];

  printf("\n%s\n", "Enter search string:");
  printf("\n%s", "> ");
  fgets(search, SIZE, stdin);

  while (search[count] != '\n') {
    count++;
  }

  search[count] = '\0';
  
  for (int i = 0; i <= LIMIT; i++) {

    char string[SIZE];

    printf("\n%s%d%s\n", "Enter string #", i + 1, ":");      
    printf("\n%s", "> ");
    fgets(string, SIZE, stdin);
    
    sum += searchStrings(string, search);
  }
  printf("\n%s%d\n\n", "Iterations: ", sum);
}

int searchStrings(char *string, char *search)
{
  int iterations = 0;
  char *searchPtr;
  
  searchPtr = strstr(string, search);

  if (searchPtr == NULL) {
    printf("\n%s\n", "Search failed.");        
  }
  else {

    while (searchPtr != NULL) {
      searchPtr = strstr(searchPtr + 1, search);
      iterations++;
    }
  }
  return iterations;
}
