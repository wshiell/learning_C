#include <stdio.h>

void rectangle(int side1, int side2);

int main(void)
{
  int side1, side2;

  puts("Enter the two sides of a rectangle:");
  scanf("%d%d", &side1, &side2);

  rectangle(side1, side2);
}

void rectangle(int side1, int side2)
{
  for (int row = 1; row <= side1; row++) {
    for (int column = 1; column <= side2; column++) {
      printf("%s", "*");
    }
    puts("");
  }
}
