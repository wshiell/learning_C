#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 11
#define NUMBER 1000000

int roll(void);

int main(void)
{
  srand(time(NULL));

  int result;
  int table[SIZE] = {0};
  
  for (int count = 0; count < NUMBER; count++) {

    result = roll();

    switch (result) {

    case 2:
      table[0]++;
      break;

    case 3:
      table[1]++;
      break;

    case 4:
      table[2]++;
      break;

    case 5:
      table[3]++;
      break;

    case 6:
      table[4]++;
      break;

    case 7:
      table[5]++;
      break;
      
    case 8:
      table[6]++;
      break;
      
    case 9:
      table[7]++;
      break;

    case 10:
      table[8]++;
      break;

    case 11:
      table[9]++;
      break;

    case 12:
      table[10]++;
      break;
    }
  }

  printf("%5s%15s%15s\n\n", "Sum", "Occurence", "% of answers");

  for (int count = 2; count <= SIZE + 1; count++) {
    printf("%5d%15d%15.1f\n", count, table[count - 2],
	   100 * (float) table[count - 2] / NUMBER);
  }
  puts("");

}

int roll(void)
{
  int roll1 = 1 + rand() % 6;
  int roll2 = 1 + rand() % 6;

  int sum = roll1 + roll2;

  return sum;
}
