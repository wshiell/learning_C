#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  double allowance[74];

  srand(time(NULL));

  for (int count = 0; count < 74; count++) {
    allowance[count] = rand() % 1000 + 1000;
  }

  for (int count = 0; count < 74; count++) {
    printf("%.1lf ", allowance[count]);

    if ((count + 1) % 10 == 0) {
      puts("");
    }
  }
}
