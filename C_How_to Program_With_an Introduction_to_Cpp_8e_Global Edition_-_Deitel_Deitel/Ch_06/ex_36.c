// ****************************************
//
// Chapter 6, ex_35.c
//
// ****************************************

#include <stdio.h>

void stringReverse(char string[], int total);

int main(void)
{
  char string[10];
  int total = 0;

  puts("Enter string:");
  scanf("%s", string);

  stringReverse(string, total);
  puts("");
}

void stringReverse(char string[], int total)
{
  if (string[total] == '\0') {
    ;
  }
  else {
    stringReverse(string, total + 1);
    printf("%c", string[total]);
  }
}
