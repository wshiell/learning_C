#include <stdio.h>
#include <string.h>

void bubbleSort(char *string[]);

int main(void)
{
  char *string[] = { "Melbourne", "Sydney", "Adelaide", "Hobart", "Perth",
                         "Canberra", "Mount Gambier", "NewCastle", "Darwin",
                         "Port MacQuarie", "Moonta" };

  bubbleSort(string);
}

void bubbleSort(char *string[])
{
  int c;
  char *temp;
  
  for (int i = 0; i < 10; i++) {

    for (size_t j = 0; j < 10; j++) {

      if (strcmp(string[j], string[j + 1]) > 0) {
	temp = string[j];
	string[j] = string[j + 1];
	string[j + 1] = temp;
      }
      else {
	;
      }
    }
  }

  for (size_t i = 0; i < 11; i++) {
    printf("%s\n", string[i]);
  }
}
