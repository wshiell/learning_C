#include <stdio.h>
#define MAX 10

int functionName(const int b[], size_t startSubscript, size_t size);

int main(void)
{
  int p[MAX] = { 5, 7, 2, 1, 0, 4, 3, 0, 6, 8 };

  puts("Answer is:");
  functionName(p, 0, MAX);
  puts("");
}

int functionName(const int b[], size_t startSubscript, size_t size)
{
  if (startSubscript < size) {
    functionName(b, startSubscript + 1, size);
    printf("%d ", b[startSubscript] * 5);
  }
}
