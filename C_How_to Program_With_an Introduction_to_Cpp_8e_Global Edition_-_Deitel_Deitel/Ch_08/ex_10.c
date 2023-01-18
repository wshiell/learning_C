#include <stdio.h>
#include <string.h>
#define SIZE 100

int main(void)
{
  int n;
  char string1[100], string2[50];

  puts("Enter string1:");
  fgets(string1, SIZE, stdin);

  puts("\nEnter string2:");
  fgets(string2, SIZE, stdin);  

  puts("\nEnter the number of characters of string2 to append to string1:");
  scanf("%d", &n);
  
  printf("String1: %s\nString2: %s\nn: %d\n", string1, string2, n);
  printf("%s%s\n", "Concatenated string: ", strncat(string1, string2, n));
}

