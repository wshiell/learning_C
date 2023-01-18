#include <stdio.h>
#include <string.h>

#define SIZE 100

int arrayStrCmp(char *string1, char *string2);
int arrayStrNCmp(char *string1, char *string2, size_t n);
int pointerStrCmp(char *string1, char *string2);
int pointerStrNCmp(char *string1, char *string2, size_t n);

int main(void)
{
  int n, length;
  char string1[SIZE], string2[SIZE];

  printf("\n%s\n\n%s", "Enter string1:", "> ");
  fgets(string1, SIZE, stdin);
  length = strlen(string1);
  string1[length - 1] = '\0';
  
  printf("\n%s\n\n%s", "Enter string2:", "> ");
  fgets(string2, SIZE, stdin);
  length = strlen(string2);
  string2[length - 1] = '\0';
  
  printf("\n%s\n\n%s", "Enter number of characters to compare:", "> ");
  scanf("%d", &n);
  puts("");
  
  printf("%-35s%d\n", "arrayStrCmp(string1, string2): ",
	 arrayStrCmp(string1, string2));
  printf("%-35s%d\n", "arrayStrNCmp(string1, string2): ",
	 arrayStrNCmp(string1, string2, n));  
  printf("%-35s%d\n", "pointerStrCmp(string1, string2): ",
	 pointerStrCmp(string1, string2));  
  printf("%-35s%d\n", "arrayStrNCmp(string1, string2): ",
	 pointerStrNCmp(string1, string2, n));
  puts("");
}

int arrayStrCmp(char *string1, char *string2)
{
  int equality = 0;
  
  for (size_t i = 0; string1[i] != '\0' || string2[i] != '\0'; i++) {

    if (string1[i] == string2[i]) {
      equality = 0;
    }
    else {

      if (string1[i] < string2[i]) {
	equality = -1;
	break;
      }
      else {
	equality = 1;
	break;
      }
    }
  }

  return equality;
}

int arrayStrNCmp(char *string1, char *string2, size_t n)
{
  int equality = 0;
  
  for (size_t i = 0; string1[i] != '\0' || string2[i] != '\0'; i++) {

    if (i == n) {
      break;
    }
    
    if (string1[i] == string2[i]) {
      equality = 0;
    }
    else {

      if (string1[i] < string2[i]) {
	equality = -1;
	break;
      }
      else {
	equality = 1;
	break;
      }
    }
  }

  return equality;    
}
	
int pointerStrCmp(char *string1, char *string2)
{
  int equality = 0;
  
  for (; *string1 != '\0' || *string2 != '\0'; string1++, string2++) {

    if (*string1 == *string2) {
      equality = 0;
    }
    else {

      if (*string1 < *string2) {
	equality = -1;
	break;
      }
      else {
	equality = 1;
	break;
      }
    }
  }

  return equality;  
}

int pointerStrNCmp(char *string1, char *string2, size_t n)
{
  int count = 0, equality = 0;
  
  for (; *string1 != '\0' || *string2 != '\0'; string1++, string2++) {

    if (count == n) {
      break;
    }
    
    if (*string1 == *string2) {
      equality = 0;
    }
    else {

      if (*string1 < *string2) {
	equality = -1;
	break;
      }
      else {
	equality = 1;
	break;
      }
    }
    count++;
  }

  return equality;    
}
