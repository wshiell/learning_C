#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int i = 0;
  int sum = 0;
  int s[6];
  double average = 0;
  char *string[] = { "1", "2", "3", "4", "5", "6" };
  char *stringPtr;

  while (i < 6) {

    sum += s[i] = strtod(string[i], &stringPtr);
    average = (float) sum / i;
    i++;
  }

  i = 0;
  
  while (i < 6) {
    printf("%d ", s[i]);
    i++;
  }

  printf("\n%s%d\n%s%.1lf\n", "Sum: ", sum, "Average: ", average);
}
