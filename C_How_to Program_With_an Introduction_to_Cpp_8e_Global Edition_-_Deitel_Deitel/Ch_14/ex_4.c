#include <stdio.h>
#include <string.h>

int arraySize(void);
void enterValues(int array[], int size);
void ascending(int array[], int size);
void descending(int array[], int size);
  
int main(int argc, char *argv[])
{
  if (!strcmp(argv[1], "-a") || !strcmp(argv[1], "-d")) {
  
    int size = arraySize();
    int array[size];

    enterValues(array, size);
  
    if (!strcmp(argv[1], "-a")) {

      ascending(array, size);
    }
    else {
      descending(array, size);
    }
    puts("");
  }
  else {
    puts("Invalid entry.");
  }
}

int arraySize(void)
{
  int size;
  
  printf("%s", "Enter array size: ");
  scanf("%d", &size);

  return size;
}

void enterValues(int array[], int size)
{
  int count = 0;
  
  puts("Enter array values (-1 to quit):");

  while (count < size) {
    
    printf("\n%s", "> ");
    scanf("%d", &array[count]);
    count++;
  }
}

void ascending(int array[], int size)
{
  for (size_t i = 1; i < size - 1; i++) {
  
    for (size_t j = 0; j < size - 1; j++) {

      if (array[j] > array[j + 1]) {

	int temp = array[j + 1];
	array[j + 1] = array[j];
	array[j] = temp;
      }
      else {
	;
      }
    }
  }
  
  for (size_t i = 0; i < size; i++) {

    printf("%d ", array[i]);
  }
}

void descending(int array[], int size)
{
  for (size_t i = 1; i < size - 1; i++) {
  
    for (size_t j = 0; j < size - 1; j++) {

      if (array[j] < array[j + 1]) {

	int temp = array[j + 1];
	array[j + 1] = array[j];
	array[j] = temp;
      }
      else {
	;
      }
    }
  }
  
  for (size_t i = 0; i < size; i++) {

    printf("%d ", array[i]);
  }
}
