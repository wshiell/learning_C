#include <stdio.h>

int main(void)
{
  printf("%s%c%c%c\n", "Print the character \':\n ", '*', '\'', '*');
  printf("%s%c%c%c\n", "Print the character \":\n ", '*', '\"', '*');
  printf("%s%c%c%c\n", "Print the character \?:\n ", '*', '\?', '*');
  printf("%s%c%c%c\n", "Print the character \\:\n ", '*', '\\', '*');
  printf("%s%c%c%c\n", "Print the character \\a:\n ", '*', '\a', '*');
  printf("%s%c%c%c\n", "Print the character \\b:\n ", '*', '\b', '*');
  printf("%s%c%c%c\n", "Print the character \\n:\n ", '*', '\n', '*');
  printf("%s%c%c%c\n", "Print the character \\r:\n ", '*', '\r', '*');
  printf("%s%c%c%c\n", "Print the character \\t:\n ", '*', '\t', '*');
  printf("%s%c%c%c\n", "Print the character \\v:\n ", '*', '\v', '*');  
}
