#include <stdio.h>

void packCharacters(char a, char b, char c, char d);
void displayBits(unsigned int variable);

int main(void)
{
  char a, b, c, d;

  printf("%s\n\n%s", "Enter four characters:", "> ");
  a = getchar();
  b = getchar();
  c = getchar();
  d = getchar();

  packCharacters(a, b, c, d);
}

void packCharacters(char a, char b, char c, char d)
{
  unsigned int variable = a;

  displayBits(a);
  displayBits(b);  
  displayBits(c);  
  displayBits(d);  
  
  variable <<= 8;
  variable |= b;
  variable <<= 8;
  variable |= c;
  variable <<= 8;
  variable |= d;

  displayBits(variable);
}

void displayBits(unsigned int variable)
{
  unsigned int mask = 1 << 31;

  printf("Variable: %u\n", variable);
  
  for (unsigned int i = 1; i <= 32; ++i) {

    putchar(variable & mask ? '1' : '0');
    variable <<= 1;

    if (i % 8 == 0) {
      putchar(' ');
    }
  }
  putchar('\n');
}
