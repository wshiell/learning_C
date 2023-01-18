#include <stdio.h>
#include <string.h>
#include <time.h>

#define SIZE 1000

void printIntercept(FILE * terrorPtr, struct tm tm);
void checkLine(char testLine[], char **terrorismList[3], int priorityCount[3]);
void printSummary(FILE *terrorPtr, int priorityCount[3], int totalCharacters);

int main(void)
{
  FILE * terrorPtr;
  char *priorityOne[] = { "muslim", "islam", "arab", "mosque", "Q'ran" };
  char *priorityTwo[] = { "hate", "jihad", "war", "isis", "america" };
  char *priorityThree[] = { "bomb", "attack", "jihad", "terror", "explosive", "suicide" };
  char **terrorismList[3];
  char c;
  unsigned int totalCharacters = 0;
  int priorityCount[3] = {0};

  terrorismList[0] = &priorityOne[0];
  terrorismList[1] = &priorityTwo[0];
  terrorismList[2] = &priorityThree[0];

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  
  if ((terrorPtr = fopen("testlist.txt", "r")) == NULL) {
    puts("File cannot be opened.");
  }
  else {
    printf("%s\n\n%s\n%s\n%s\n%s\n%s\n%s\n\n",
	   "*** Terrorist Communication Alert Program ***",
	   "This program is intended to give an indication of the threat level",
	   "of intercepted communications. It works by analysing the text, looking",
	   "for key words which may or may not be hallmarks of terrorist activity.",
	   "The program assigns a ranking to each key word, then estimates the ",
	   "threat level by summing the total value of all key words.",
	   "The higher the value of the estimate, the greater the threat is deemed to be.");

    printIntercept(terrorPtr, tm);

    fseek(terrorPtr, 0, SEEK_SET);
    
    while (!feof(terrorPtr))  {

      c = fgetc(terrorPtr);      
      totalCharacters++;
    }

    totalCharacters--;
    char testLine[totalCharacters];
    testLine[totalCharacters - 1] = '\0';
    fseek(terrorPtr, 0, SEEK_SET);

    for (unsigned int i = 0; i < totalCharacters - 1; i++) {

      c = fgetc(terrorPtr);
      testLine[i] = c;
    }
    checkLine(testLine, terrorismList, priorityCount);
    printSummary(terrorPtr, priorityCount, totalCharacters);
  }

  fclose(terrorPtr);
}

void checkLine(char testLine[], char **terrorismList[3], int priorityCount[3])
{
  char *testPtr;

  for (unsigned int i = 0; i < 3; i++) {

    for (unsigned int j = 0; j < 5; j++ ) {

      testPtr = testLine;

      while ((testPtr = strstr(testPtr, terrorismList[i][j])) != NULL) {
	priorityCount[i]++;
	testPtr += strlen(terrorismList[i][j]);
      }
    }
  }
}

void printIntercept(FILE * terrorPtr, struct tm tm)
{

  char c, interceptText[SIZE];
  int i = 0;

  printf("%s\n%s%d/%d/%d %d:%d\n\n", "** Text Intercept **", "Received: ",
	  tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);
  
  while (i < SIZE - 1) {
      c = fgetc(terrorPtr);
      interceptText[i++] = c;
  }
  printf("%s\n\n", interceptText);
}

void printSummary(FILE *terrorPtr, int priorityCount[3], int totalCharacters)
{
  int pointTotal = priorityCount[0] * 1 + priorityCount[1] * 2 + priorityCount[2] * 3;
  
  printf("Priority One: %d\n", priorityCount[0] * 1);
  printf("Priority Two: %d\n", priorityCount[1] * 2);
  printf("Priority Three: %d\n", priorityCount[2] * 3);

  printf("Point total of whole message: %d\n",
	 pointTotal);
  printf("\n%s%d\n", "Total character length of intercepted message: ", totalCharacters);
  printf("%s\n%lf\n", "Estimatede threat level of message (length / priority rating):",
	 (float) pointTotal / totalCharacters);
}
