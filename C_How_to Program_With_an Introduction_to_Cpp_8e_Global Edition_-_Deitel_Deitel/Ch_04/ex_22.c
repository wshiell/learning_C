#include <stdio.h>

int main(void)
{
  unsigned int aCount = 0;
  unsigned int bCount = 0;
  unsigned int cCount = 0;
  unsigned int dCount = 0;
  unsigned int fCount = 0;
  unsigned int total = 0;
  unsigned int  average = 0;
  
  puts("Enter the letter grades:");
  puts("Enter the EOF character to end input.");
  int grade;

  while ((grade = getchar()) != EOF) {

    switch (grade) {

    case 'A':
    case 'a':
      ++aCount;
      break;

    case 'B':
    case 'b':
      ++bCount;
      break;

    case 'C':
    case 'c':
      ++cCount;
      break;

    case 'D':
    case 'd':
      ++dCount;
      break;

    case 'F':
    case 'f':
      ++fCount;
      break;

    case '\n':
    case '\t':
    case ' ':
      break;

    default:
      printf("%s", "Incorrect letter grade entered.");
      puts(" Enter a new grade.");
      break;
    }
  }

  puts("\nTotals for each letter grade are:");
  printf("A: %u\n", aCount);
  printf("B: %u\n", bCount);
  printf("C: %u\n", cCount);
  printf("D: %u\n", dCount);
  printf("F: %u\n", fCount);

  total = aCount * 1 + bCount * 2 + cCount * 3 + dCount * 4 + fCount * 5;
  average = total / (aCount + bCount + cCount + dCount + fCount) + 64;

  if (average == 69) {
    average = 70;
  }

  puts("");
  printf("Average grade is: %c\n", average);
}