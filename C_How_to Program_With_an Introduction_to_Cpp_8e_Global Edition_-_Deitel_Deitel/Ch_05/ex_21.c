#include <stdio.h>

void rectangle(int side1, int side2, char fillCharacter);
void square(int side1, char fillCharacter);
void diamond(int side1, char fillCharacter);
void parallelogram(int side1, int side2, char fillCharacter);
void rightAngledTriangle(int side1, int side2, char fillCharacter);
void isocelesTriangle(int side1, char fillCharacter);

int main(void)
{
  int side1, side2;
  int counter = 0;

  puts("Enter two numbers:");
  scanf("%d", &side1);
  scanf("%d", &side2);

  puts("Enter a character to fill the shape:");
  int c;
  scanf("%d", &c);
  c = getchar();

  while (side1 != -1) {
    
    if (counter != 0) {
      scanf("%d", &side2);
    }

    counter++;

    rectangle(side1, side2, c);
    square(side1, c);
    diamond(side1, c);
    parallelogram(side1, side2, c);
    rightAngledTriangle(side1, side2, c);
    isocelesTriangle(side1, c);

    puts("Enter two numbers:");
    scanf("%d", &side1);
  }
}

void rectangle(int side1, int side2, char fillCharacter)
{
  for (int row = 1; row <= side1; row++) {
    for (int column = 1; column <= side2; column++) {
      printf("%c", fillCharacter);
    }
    puts("");
  }
  puts("");
}

void square(int side1, char fillCharacter)
{
  for (int row = 1; row <= side1; row++) {
    for (int column = 1; column <= side1; column++) {
      printf("%c", fillCharacter);
    }
    puts("");
  }
  puts("");
}

void diamond(int side1, char fillCharacter)
{
  int  side = side1 * 2 - 1;
  
  for (int row = 1; row <= side; row++) {

    if (row <= ((side / 2) + 1)) {

      for (int space = side / 2; space >= row; space--) {
	printf("%s", " ");
      }

      for (int column = 1; column <= 2 * (row - 1) + 1; column++) {
	printf("%c", fillCharacter);
      }
      puts("");
    }
    else {
  
      for (int space = 1; space <= row - (side / 2 + 1); space++) {
    	printf("%s", " ");
      }

      for (int column = side; column >= 2 * row - side; column--) {
    	printf("%c", fillCharacter);
      }
      puts("");
    }
  }
  puts("");
}

void parallelogram(int side1, int side2, char fillCharacter)
{
  for (int row = 1; row <= side1; row++) {
    for (int space = 1; space < row; space++) {
      printf("%s", " ");
    }
    for (int symbol = 1; symbol <= side2; symbol++){
      printf("%c", fillCharacter);
    }

    puts("");
  }
}

void rightAngledTriangle(int side1, int side2, char fillCharacter)
{
  for (int row = 1; row <= side1; row++) {
    for (int column = 1; column <= row; column++) {
      printf("%c", fillCharacter);
    }
    puts("");
  }
  puts("");
}

void isocelesTriangle(int side1, char fillCharacter)
{
  for (int row = 1; row <= side1; row++) {

    for (int space = side1; space > row; space--) {
      printf("%s", " ");
    }

    for (int column = 1; column <= 2 * (row - 1) + 1; column++) {
      printf("%c", fillCharacter);
    }
    puts("");
  }
  puts("");
}


