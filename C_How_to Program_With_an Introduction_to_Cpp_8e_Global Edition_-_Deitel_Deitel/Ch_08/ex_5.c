#include <stdio.h>
#include <ctype.h>

int main(void)
{
  char c;
  
  puts("Enter a character:");
  scanf("%c", &c);

  printf("\'%c\'%s%s\n", c, isblank(c) ? " is a " : " is not a ", "blank character");
  printf("\'%c\'%s%s\n", c, isdigit(c) ? " is a " : " is not a ", "digit");
  printf("\'%c\'%s%s\n", c, isalpha(c) ? " is a " : " is not a ", "letter");
  printf("\'%c\'%s%s\n", c, isalnum(c) ? " is a " : " is not a ", "letter or number");
  printf("\'%c\'%s%s\n", c, isxdigit(c) ? " is a " : " is not a ", "hexadecimal digit");
  printf("\'%c\'%s%s\n", c, islower(c) ? " is a " : " is not a ", "lowercase letter");
  printf("\'%c\'%s%s\n", c, isupper(c) ? " is a " : " is not a ", "uppercase");
  printf("\'%c\'%s%s\n", c, isspace(c) ? " is a " : " is not a ", "space");
  printf("\'%c\'%s%s\n", c, iscntrl(c) ? " is a " : " is not a ", "control character");
  printf("\'%c\'%s%s\n", c, ispunct(c) ? " is a " : " is not a ", "printing character"
	 " other than space, a digit or a letter ");
  printf("\'%c\'%s%s\n", c, isprint(c) ? " is a " : " is not a ", "printing character");
  printf("\'%c\'%s%s\n", c, isgraph(c) ? " is a " : " is not a ", "printing character "
	 "other than space");
}
