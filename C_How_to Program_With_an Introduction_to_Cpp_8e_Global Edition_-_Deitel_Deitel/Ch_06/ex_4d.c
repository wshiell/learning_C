#include <stdio.h>
#define SIZE 3

int main(void)
{
  int table[SIZE][SIZE];
 
  for (int x = 0; x < SIZE; x++) {
    for (int y = 0; y < SIZE; y++) {
      table[x][y] = x + y;
    }
  }

  for (int x = 0; x < SIZE; x++) {
    for (int y = 0; y < SIZE; y++) {
      printf("%d ", table[x][y]);
    }
    puts("");
  }

  puts("");
  
  int table2[SIZE][SIZE] = { { 1, 8 }, { 2, 4, 6 }, { 5 } };  

  for (int x = 0; x < SIZE; x++) {
    for (int y = 0; y < SIZE; y++) {
      printf("%d ", table2[x][y]);
    }
    puts("");
  }
}
