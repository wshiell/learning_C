#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int i = 0;
  double sum = 0;
  double average = 0;
  double s[6];
  char *string[] = {"1.1", "2.2", "3.3", "4.4", "5.5", "6.6" };
  char *stringPtr;

  while (i < 6) {

    sum += s[i] = strtod(string[i], &stringPtr);
    average = (float) sum / i;
    i++;
  }

  i = 0;
  
  while (i < 6) {

    printf("%.3lf ", s[i]);
    i++;
  }

  printf("\n%s%.1lf\n%s%.1lf\n", "Sum: ", sum, "Average: ", average);
}
/* #include <stdio.h> */
/* #include <stdlib.h> */

/* int main(void) */
/* { */
/*   int i = 0; */
/*   char *stringPtr; */

/*   while (i < 6) { */

/*     s[i] = strtod(string[i], &stringPtr); */
/*     i++; */
/*   } */

/*   i = 0; */
  
/*   while (i < 6) { */

/*     i++; */
/*   } */
/*   puts(""); */
/* } */
