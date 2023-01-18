#include <stdio.h>
#include <string.h>

#define SIZE 100

char* arrayStrCat(char *string1, char *string2);
char* arrayStrNCat(char *string1, char *string2, int n);
char* pointerStrCat(char *string1, char *string2);
char* pointerStrNCat(char *string1, char *string2, int n);
char* arrayStrCpy(char *string1, char *string2);
char* arrayStrNCpy(char *string1, char *string2, int n);
char* pointerStrCpy(char *string1, char *string2);
char* pointerStrNCpy(char *string1, char *string2, int n);

int main(void)
{
  int n;
  char string1[SIZE], string2[SIZE];
  int length;
  
  printf("\n%s\n\n%s", "Enter string1:", "> ");
  fgets(string1, SIZE, stdin);
  length = strlen(string1);
  string1[length - 1] = '\0';
  
  printf("\n%s\n\n%s", "Enter string2:", "> ");
  fgets(string2, SIZE, stdin);
  length = strlen(string2);
  string2[length - 1] = '\0';
  
  printf("\n%s\n\n%s", "Enter number of characters to copy/append:", "> ");
  scanf("%d", &n);
  
  printf("\n%s\n%s%s\n%s%s\n%s%s\n", "arrayStrCat(string1, string2):",
	 "String1 before concatenation: ", string1,
	 "String2 before concatenation: ", string2,
	 "String1 after concatenation: ", arrayStrCat(string1, string2));
  printf("\n%s\n%s%s\n%s%s\n%s%s\n", "arrayStrNCat(string1, string2, n):",
	 "String1 before concatenation: ", string1,
	 "String2 before concatenation: ", string2,
	 "String1 after concatenation: ", arrayStrNCat(string1, string2, n));
  printf("\n%s\n%s%s\n%s%s\n%s%s\n", "pointerStrCat(string1, string2):",
	 "String1 before concatenation: ", string1,
	 "String2 before concatenation: ", string2,
	 "String1 after concatenation: ", pointerStrCat(string1, string2));
  printf("\n%s\n%s%s\n%s%s\n%s%s\n", "pointerStrNCat(string1, string2, n):",
	 "String1 before concatenation: ", string1,
	 "String2 before concatenation: ", string2,
	 "String1 after concatenation: ", pointerStrNCat(string1, string2, n));
  printf("\n%s\n%s%s\n%s%s\n%s%s\n", "arrayStrCpy(string1, string2):",
	 "String1 before copying: ", string1,
	 "String2 before copying: ", string2,
	 "String1 after copying: ", arrayStrCpy(string1, string2));
  printf("\n%s\n%s%s\n%s%s\n%s%s\n", "arrayStrNCpy(string1, string2, n):",
	 "String1 before copying: ", string1,
	 "String2 before copying: ", string2,
	 "String1 after copying: ", arrayStrNCpy(string1, string2, n));
  printf("\n%s\n%s%s\n%s%s\n%s%s\n", "pointerStrCpy(string1, string2):",
	 "String1 before copying: ", string1,
	 "String2 before copying: ", string2,
	 "String1 after copying: ", pointerStrCpy(string1, string2));
  printf("\n%s\n%s%s\n%s%s\n%s%s\n", "pointerStrNCpy(string1, string2, n):",
	 "String1 before copying: ", string1,
	 "String2 before copying: ", string2,
	 "String1 after copying: ", pointerStrNCpy(string1, string2, n));

  puts("");
}

char* arrayStrCat(char *string1, char *string2)
{
  int length1 = strlen(string1);
  int length2 = strlen(string2);
  char temp[length1 + length2];
  char *tempPtr;

  tempPtr = temp;
  
  for (size_t i = 0; i < length1; i++) {

    temp[i] = string1[i];
  }

  for (size_t i = 0; i < length2; i++) {

    temp[length1 + i] = string2[i];
  }

  temp[length1 + length2] = '\0';
    
  return tempPtr;
}

char* arrayStrNCat(char *string1, char *string2, int n)
{
  int length1 = strlen(string1);
  int length2 = strlen(string2);
  char temp[length1 + length2];
  char *tempPtr;

  tempPtr = temp;
  
  for (size_t i = 0; i < length1; i++) {

    temp[i] = string1[i];
  }

  for (size_t i = 0; i < length2; i++) {

    if (i < n) {
     temp[length1 + i] = string2[i];
    }
    else {
      i = length2;
    }
  }

  temp[length1 + n] = '\0';

  return tempPtr;
}
	
char* pointerStrCat(char *string1, char *string2)
{
  int length1 = strlen(string1);
  int length2 = strlen(string2);
  char temp[length1 + length2];
  char *tempPtr;

  tempPtr = &*temp;

  for (; *string1 != '\0'; tempPtr++, string1++) {

    *tempPtr = *string1;
  }
  
  for (; *string2 != '\0'; tempPtr++, string2++) {

    *tempPtr = *string2;
  }

  *tempPtr = '\0';

  tempPtr = &*temp;

  return tempPtr;
}

char* pointerStrNCat(char *string1, char *string2, int n)
{
  int count = 0;
  int length1 = strlen(string1);
  int length2 = strlen(string2);
  char temp[length1 + length2];
  char *tempPtr;

  tempPtr = &*temp;

  for (; *string1 != '\0'; tempPtr++, string1++) {

    *tempPtr = *string1;
  }
  
  for (; *string2 != '\0'; tempPtr++, string2++) {

    if (count != n) {
      *tempPtr = *string2;
      count++;
    }
    else {
      break;
    }
  }

  *tempPtr = '\0';

  tempPtr = &*temp;

  return tempPtr;
}
char* arrayStrCpy(char *string1, char *string2)
{
  int length1 = strlen(string1);
  int length2 = strlen(string2);
  char temp[length1 + length2];
  char *tempPtr;

  tempPtr = temp;
  
  for (size_t i = 0; i < length2; i++) {

    temp[i] = string2[i];
  }

  temp[length2] = '\0';
    
  return tempPtr;
}

char* arrayStrNCpy(char *string1, char *string2, int n)
{
  int length1 = strlen(string1);
  int length2 = strlen(string2);
  char temp[length1 + length2];
  char *tempPtr;

  tempPtr = temp;
  
  for (size_t i = 0; i < length2; i++) {

    if (i < n) {
      temp[i] = string2[i];
    }
    else {
      i = length2;
    }
  }

  for (int i = n; i < length1 + length2; i++) {
    temp[i] = '\0';
  }

  return tempPtr;
}
	
char* pointerStrCpy(char *string1, char *string2)
{
  int length1 = strlen(string1);
  int length2 = strlen(string2);
  char temp[length1 + length2];
  char *tempPtr;

  tempPtr = temp;
  
  for (; *string2 != '\0'; string2++, tempPtr++) {

    *tempPtr = *string2;
  }

  *tempPtr = '\0';

  tempPtr = &*temp;
    
  return tempPtr;
}

char* pointerStrNCpy(char *string1, char *string2, int n)
{
  int count = 0;
  int length1 = strlen(string1);
  int length2 = strlen(string2);
  char temp[length1 + length2];
  char *tempPtr;

  tempPtr = temp;
  
  for (; *string2 != '\0'; string2++, tempPtr++) {

    if (count != n) {
      *tempPtr = *string2;
      count++;
    }
    else {
      break;
    }
  }

  for (int i = n; i < length1 + length2; i++) {
    *tempPtr = '\0';
  }  

  tempPtr = &*temp;
    
  return tempPtr;
}
