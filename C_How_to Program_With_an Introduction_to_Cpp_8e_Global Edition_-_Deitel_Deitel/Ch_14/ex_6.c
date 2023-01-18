#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int size;
  
  puts("Enter the size of the array:");
  scanf("%d", &size);
  
  int *array = calloc(size, size);
  
  printf("%s%d%s\n", "Enter ", size, " values:");

  for (int i = 0; i < size; i++) {

    scanf("%d", &array[i]);
  }

  for (size_t i = 0; i < size; i++) {

    printf("%d ", array[i]);
  }
  puts("");

  size /= 2;
  
  array = realloc(array, size);

  for (size_t i = 0; i < size; i++) {

    printf("%d ", array[i]);
  }
  puts("");
  
}
