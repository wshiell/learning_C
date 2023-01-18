#include <stdio.h>

int isAlpha(char c);
int isDigit(char c);
int isAlnum(char c);
int isBlank(char c);
int isXdigit(char c);
int isUpper(char c);
int isLower(char c);
void toUpper(char c);
void toLower(char c);
int isCntrl(char c);
int isPunct(char c);
int isPrint(char c);
int isSpace(char c);
int isGraph(char c);

int main(void)
{
  char c;

  puts("** Note: Have not correctly handled the input of control characters **\n");
  puts("*** Character Handling Functions ***\n");

  printf("%s\n\n%s", "Enter a character:", "> ");
  scanf("%c", &c);
  puts("");
  
  printf("%c%s%d\n", c, " in ASCII code: ", c);
  printf("%c%s%s\n", c, isAlpha(c) ? " is a " : " is not a ", "letter.");
  printf("%c%s%s\n", c, isDigit(c) ? " is a " : " is not a ", "digit.");  
  printf("%c%s%s\n", c, isAlnum(c) ? " is a " : " is not a ", "letter or digit.");
  printf("%c%s%s\n", c, isBlank(c) ? " is a " : " is not a ", "blank character.");    
  printf("%c%s%s\n", c, isXdigit(c) ? " is a " : " is not a ", "hexademical digit.");
  printf("%c%s%s\n", c, isUpper(c) ? " is an " : " is not an ", "uppercase letter.");
  printf("%c%s%s\n", c, isLower(c) ? " is a " : " is not a ", "lowercase letter.");
  toUpper(c);
  toLower(c);
  printf("%c%s%s\n", c, isCntrl(c) ? " is a " : " is not a ", "control character.");
  printf("%c%s%s\n", c, isPunct(c) ? " is a " : " is not a ",
	 "punctuation character.");
  printf("%c%s%s\n", c, isPrint(c) ? " is a " : " is not a ", "print character.");
  printf("%c%s%s\n", c, isSpace(c) ? " is a " : " is not a ", "space character.");
  printf("%c%s%s%s\n", c, isGraph(c) ? " is a " : " is not a ", "print character ",
	 "other than space.");
  puts("");
}

int isAlpha(char c)
{
  if ((c >= 65 && c <= 90)  ||  (c >= 97 && c <= 122)) {
    return 1;    
  }
  else {
    return 0;
  }
}

int isDigit(char c)
{
  if (c >= 48 && c <= 57) {
    return 1;    
  }
  else {
    return 0;
  }    
}

int isAlnum(char c)
{
  if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)){
    return 1;
  }
  else {
    return 0;
  }
}

int isBlank(char c)
{
  if (c == 23) {
    return 1;
  }
  else {
    return 0;
  }
}

int isXdigit(char c)
{
  if ((c >= 48 && c <= 57) || (c >= 65 && c <= 70)) {
    return 1;
  }
  else {
    return 0;
  }
}

int isUpper(char c)
{
  if (c >= 65 && c <= 90) {
    return 1;
  }
  else {
    return 0;
  }
}

int isLower(char c)
{
  if (c >= 97 && c <= 122) {
    return 1;
  }
  else {
    return 0;
  }
}

void toUpper(char c)
{
  printf("%s", "toUpper(): ");
    
  if (c >= 65 && c <= 90) {
    printf("%s%c\t%s%c\n", "Before conversion: ", c, "After conversion: ", c);
  }
  else {

    if (c >= 97 && c <= 122) {
    printf("%s%c\t%s%c\n", "Before conversion: ", c, "After conversion: ", c - 32);
    }
    else {
      printf("%c%s\n", c, " is not a letter.");
    }
  }
}

void toLower(char c)
{
  printf("%s", "toLower(): ");
  
  if (c >= 97 && c <= 122) {
    printf("%s%c\t%s%c\n", "Before conversion: ", c, "After conversion: ", c);
  }
  else {

    if (c >= 65 && c <= 90) {
    printf("%s%c\t%s%c\n", "Before conversion: ", c, "After conversion: ", c + 32);
    }
    else {
      printf("%c%s\n", c, " is not a letter.");
    }
  }
}

int isCntrl(char c)
{
  if (c == 32 || c == 10 || c == 12 || c == 12 || c == 9 || c == 11 || c == 7 ||
      c == 8) {
    return 1;
  }
  else {
    return 0;
  }
}

int isPunct(char c)
{
  if ((c >= 33 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96) ||
      (c >= 123 && c <= 126)) {
    return 1;
  }
  else {
    return 0;
  }
}

int isPrint(char c)
{
  if (c >= 32 || c <= 126) {
    return 1;
  }
  else {
    return 0;
  }
}

int isSpace(char c)
{
  if (c == 32 || c == 10 || c == 12 || c == 12 || c == 9 || c == 11) {
    return 1;
  }
  else {
    return 0;
  }
}

int isGraph(char c)
{
  if (c >= 33 && c <= 126) {
    return 1;
  }
  else {
    return 0;
  }  
}
