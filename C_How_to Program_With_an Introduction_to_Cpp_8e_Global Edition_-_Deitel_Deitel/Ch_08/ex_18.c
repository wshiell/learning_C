#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 10000

void testCharacters(char string[SIZE]);
double tokeniseString(char *string);

int main(void)
{
  int count = 0;
  char string[SIZE];

  printf("\n%s\n", "Enter a line of text:");
  printf("\n%s", "> ");
  fgets(string, SIZE, stdin);

  while (string[count] != '\n') {
    count++;
  }

  string[count] = '\0';
  
  testCharacters(string);
}

void testCharacters(char string[SIZE])
{
  int checkString(char *candidateString, char *testString);
  double average, ratio;
  int consonantCount = 0, digitCount = 0, spaceCount = 0, vowelCount = 0;
  char *vowels = "AEIOUaeiou";
  char *consonants = "BCDFGHJKLMNPQRTSVWXYZbcdfghjklmnpqrtsvwxyz";
  char *digits = "0123456789";
  char *spaces = " ";

  consonantCount = checkString(string, consonants);
  digitCount = checkString(string, digits);
  spaceCount = checkString(string, spaces);
  vowelCount = checkString(string, vowels);
  
  printf("\nConsonants: %d\n", consonantCount);
  printf("Vowels: %d\n", vowelCount);
  printf("Digits: %d\n", digitCount);
  printf("Spaces: %d\n", spaceCount);

  average = tokeniseString(string);
  ratio = (float) vowelCount / consonantCount;
  
  printf("\nRatio of vowels to consonants: %.3lf", ratio);
  printf("\nAverage word length: %.3lf\n", average);
  printf("Ratio of average word length to vowel/consonant ratio: %.3lf\n\n",
  	 average / ratio);
}

int checkString(char *candidateString, char *testString)
{
  int counter = 0;
  
  char *testPtr = strpbrk(candidateString, testString);

  if (testPtr == NULL) {
    return 0;
  }
  else {

    while (testPtr != NULL) {
      testPtr = strpbrk(testPtr + 1, testString);
      counter++;
    }
  }
  return counter;
}

double tokeniseString(char *string)
{
  int sum = 0;
  int count = 0;
  int punct = 0;
  double average = 0;
  char *stringPtr;
  
  stringPtr = strtok(string, " ");
  
  while (stringPtr != NULL) {

    int i = 0;

    while (ispunct(stringPtr[i]) != 0) {
      i++;
      punct++;
    }

    while (isalpha(stringPtr[i]) != 0) {

      if (ispunct(stringPtr[i + 1]) != 0) {
	sum++;
	i += 2;
      }
      else {
	sum++;
	i++;
      }
    }

    stringPtr = strtok(NULL, " ");
    count++;
  }

  printf("\nNon alphanum/space characters: %d", punct);
  printf("\nTotal letters: %d", sum);
  printf("\nTotal words: %d\n", count);
  average = (double) sum / count;
  return average;
}
