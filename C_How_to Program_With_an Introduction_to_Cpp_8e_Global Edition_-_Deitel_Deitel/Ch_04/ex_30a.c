#include <stdio.h>

int main(void)
{
  unsigned int aCount = 0;
  unsigned int bCount = 0;
  unsigned int cCount = 0;
  unsigned int dCount = 0;
  unsigned int fCount = 0;

  puts("Enter the letter grades:");
  puts("Enter the EOF character to end input.");

  int grade;
  
  while ((grade = getchar()) != EOF) {

    if (grade == 'a' || grade == 'A') {
      ++aCount;
    }
    else if (grade == 'b' || grade == 'B' ) {
      ++bCount;
    }
    else if (grade == 'c' || grade == 'C') {
      ++cCount;
    }
    else if (grade == 'd' || grade == 'D') {
      ++dCount;
    }
    else if (grade == 'f' || grade == 'F') {
      ++fCount;
    }
    else if (grade == ' ' || grade == '\t' || grade == '\n') {
      printf("%s", "");
    }
    else {
      printf("%s", "Incorrect letter grade entered.");
      puts(" Enter a new grade.");
    }
  }
  
  puts("\nTotals for each letter grade are:");
  printf("A: %u\n", aCount);
  printf("B: %u\n", bCount);
  printf("C: %u\n", cCount);
  printf("D: %u\n", dCount);
  printf("F: %u\n", fCount);
  
}
