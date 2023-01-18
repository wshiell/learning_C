#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flipCoin(void);

int main(void)
{
  srand(time(NULL));

  int heads = 0, tails = 0;
  
  for (int flip = 1; flip <= 1000000; flip++) {
    int face = flipCoin();

    if (face == 0) {
      puts("Heads");
      tails++;
    }
    else {
      puts("Tails");
	heads++;
    }
  }
  
  printf("\nHeads: %d\n", heads);
  printf("Tails: %d\n", tails);
}

int flipCoin(void)
{
  int flip;

  flip = rand() % 2;

  if (flip == 1) {
    return 0;
  }
  else {
    return 1;
  }
}
