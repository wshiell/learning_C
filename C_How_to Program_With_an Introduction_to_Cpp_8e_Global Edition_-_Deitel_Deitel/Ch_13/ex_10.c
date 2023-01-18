#include <stdio.h>

#define SIZE 10
#define PRINTARRAY(array, size) for (size_t i = 0; i < size; i++) {printf("%d ", array[i]);} puts("");
#define SUMMARY(array, size) int total = 0; for (size_t i = 0; i < size; i++) { total += array[i];} printf("Array size = %d", total); puts("");

int main(void)
{
  int numbers[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  PRINTARRAY(numbers, SIZE)
  SUMMARY(numbers, SIZE)
}
