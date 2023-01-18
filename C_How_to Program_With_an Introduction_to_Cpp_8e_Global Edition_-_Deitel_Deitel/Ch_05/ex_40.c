#include <stdio.h>

int main(void) {
  int count = 1;
  count++;
  if (count < 10) {
    main();
    printf("Count = %d\n", count);
  }
}
