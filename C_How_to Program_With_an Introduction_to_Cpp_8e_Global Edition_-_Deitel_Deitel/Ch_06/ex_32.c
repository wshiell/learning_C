// ****************************************
//
// Chapter 6, ex_32.c
//
// ****************************************

#include <stdio.h>
#define MAX 10

int functionName(const int b[], int c[], size_t startSubscript, size_t size);
int linearSearch(const int b[], int size, int searchKey);

int main(void)
{
  int result;
  int searchKey = 25;
  int p[MAX] = { 5, 7, 2, 1, 0, 4, 3, 0, 6, 8 };
  int q[MAX] = {0};

  puts("Answer is:");
  functionName(p, q, 0, MAX);
  puts("");

  result = linearSearch(q, MAX, searchKey);

  if (result != 0) {
    printf("Search key found at index %d\n", result);
  }
  else {
    puts("Search key not found");
  }

  for (int count = 0; count < MAX; count++) {
    printf("%3d", q[count]);
  }
  puts("");
}

int functionName(const int b[], int c[], size_t startSubscript, size_t size)
{
  if (startSubscript < size) {
    functionName(b, c, startSubscript + 1, size);
    printf("%3d", b[startSubscript] * 5);
    c[size - startSubscript - 1] = b[startSubscript] * 5;
  }
}

int linearSearch(const int b[], int size, int searchKey)
{
  if (size != -1) {

    if (b[size - 1] == searchKey) {
      return size;
    }
    else {
      linearSearch(b, size - 1, searchKey);
    }
  }
  else {
    return 0;
  }
}
