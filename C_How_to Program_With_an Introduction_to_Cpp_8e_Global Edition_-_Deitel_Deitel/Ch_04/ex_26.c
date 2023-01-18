#include <stdio.h>
#include <math.h>

int main(void)
{
  int terms;
  double precision;

  puts("Enter precision:");
  scanf("%lf", &precision);
  puts("Enter number of terms (-1 to quit):");
  scanf("%d", &terms);
  
  while (terms != -1) {
    double pi = 0;

    printf("%7s%22s\n\n", "nth term", "value of pi");
    printf("%s\n", "*****************************");

    for (unsigned int counter = 0; counter < terms; counter++) {
      pi += pow(-1, counter) * (float) 4 / (1 + counter * 2); 

      printf("%7u%22lf", counter + 1, pi);

      int testPi = pi * 1000000;
      int testPrecis = precision * 1000000;
      if (testPi == testPrecis) {
	int num = terms;
      	printf("\tPi is equal to or greater than %.10lf at %d\n",
	       precision, num);
      	break;
      }

      puts("");
    }
    puts("");
    puts("Enter number of terms (-1 to quit):");
    scanf("%d", &terms);
  } 
}
