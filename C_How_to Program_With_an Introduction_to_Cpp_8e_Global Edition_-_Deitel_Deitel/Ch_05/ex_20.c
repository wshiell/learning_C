#include <stdio.h>

void rectangle(int side1, int side2, char fillCharacter);

int main(void)
{
  int side1, side2;

  puts("Enter the two sides of a rectangle:");
  scanf("%d%d", &side1, &side2);

  puts("Enter a character to fill the rectangle:");
  int c;
  scanf("%d", &c);
  c = getchar();

  rectangle(side1, side2, c);
}

void rectangle(int side1, int side2, char fillCharacter)
{
  for (int row = 1; row <= side1; row++) {
    for (int column = 1; column <= side2; column++) {
      printf("%c", fillCharacter);
    }
    puts("");
  }
}
