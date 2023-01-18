#include <stdio.h>

int main(void)
{
  float array[10] = {0};
  float *arrayPtr;

  arrayPtr = array;

  printf("sizeof(array) = %lu\n", sizeof array);
  printf("sizeof(*arrayPtr) = %lu\n", sizeof(*arrayPtr));
}
