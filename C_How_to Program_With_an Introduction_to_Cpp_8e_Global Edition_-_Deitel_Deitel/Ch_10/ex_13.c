#include <stdio.h>

void unpackCharacters(unsigned int characters);
void displayBits(unsigned int variable);

int main(void)
{
  unsigned int characters;

  printf("%s\n\n%s", "Enter a character:", "> ");
  scanf("%u", &characters);

  unpackCharacters(characters);
}

void unpackCharacters(unsigned int characters)
{
  unsigned int input = characters;
  unsigned int mask = 4278190080;
  unsigned int a, b, c, d;

  displayBits(input);    
  
  a = input &= mask;
  a >>= 24;

  displayBits(a);

  input = characters;
  mask = 16711680;
  b = input &= mask;
  b >>= 16;

  displayBits(b);  

  input = characters;
  mask = 65280;
  c = input &= mask;
  c >>= 8;

  displayBits(c);  

  input = characters;
  mask = 255;
  d = input &= mask;

  displayBits(d);  
}

void displayBits(unsigned int variable)
{
  unsigned int mask = 1 << 31;

  for (unsigned int i = 1; i <= 32; ++i) {

    putchar(variable & mask ? '1' : '0');
    variable <<= 1;

    if (i % 8 == 0) {
      putchar(' ');
    }
  }
  putchar('\n');
}
