#include <stdio.h>
#include <string.h>
#include <math.h>
#define SIZE 100

double strToD(char *string, int length, char** Ptr);
long int strToL(char *string, int length, char** Ptr);
unsigned long int strToUL(char *string, int length, char** Ptr);

int main(void)
{
  char string[SIZE];
  char *doublePtr, *longPtr, *unsignedPtr;
  int length;

  puts("\nEnter a string containing an integer or a double:");
  printf("\n%s", "> ");
  
  fgets(string, SIZE, stdin);

  length = strlen(string) - 1;
  
  string[length] = '\0';

  double doubNum = strToD(string, length, &doublePtr);
  long int longNum = strToL(string, length, &longPtr);
  unsigned long int unsigNum = strToUL(string, length, &unsignedPtr);

  for (size_t i = 0; i < 3; i++) {

  }
  
  if (doubNum != 0) {
    printf("\n%s\n%s%s\n%s%lf\n%s%s\n", "Double: ",
	   "The original string: ", string,
	   "The numerical portion: ", doubNum,
	   "The non-numerical portion: ", doublePtr);
  }

  if (longNum != 0) {
    printf("\n%s\n%s%s\n%s%d\n%s%s\n", "Long: ",
	   "The original string: ", string,
	   "The numerical portion: ", longNum,
	   "The non-numerical portion: ", longPtr);
  }

  if (unsigNum != 0) {
    printf("\n%s\n%s%s\n%s%u\n%s%s\n", "Unsigned",
	   "The original string: ", string,
	   "The numerical portion: ", unsigNum,
	   "The non-numerical portion: ", unsignedPtr);
  }
  
  puts("");
}

double strToD(char *string, int length, char** Ptr)
{
  double converted, decimal = 0, integer = 0;
  int negative = 0, period = 0, count = 0;
  
  for (size_t i = 1; i <= length; i++) {

    if (string[i - 1] == 45 && string[i] >= 48 && string[i] <= 57) {
      negative++;
    }
    
    if (string[i] == 46 && string[i + 1] >= 48 && string[i + 1] <= 57) {
      period++;
    }

    if (string[i] >= 48 && string[i] <= 57 && period != 0) {
      decimal += pow(10, -(count + 1)) * (string[i] - 48);
      count++;
    }
    if (string[i - 1] >= 48 && string[i - 1] <= 57 && (string[i] < 48 || string[i] > 57)) {
      *Ptr = &string[i];
    }    
  }

  period = 0;
  count = 0;

  for (size_t i = length; i > 0; i--) {

    if (string[i - 1] >= 48 && string[i - 1] <= 57 && period != 0) {
      integer += pow(10, count) * (string[i - 1] - 48);
      count++;
    }

    if (string[i - 2] == 46 && string[i - 1] >= 48 && string[i - 1] <= 57) {
      period++;
    }
  }
  
  converted = decimal + integer;

  if (negative != 0) {
    converted *= -1;
  }

  if (period != 0) {
    return converted;
  }
  else {
    return 0;
  }
}

long int strToL(char *string, int length, char** Ptr)
{
  int negative = 0, count = 0, integer = 0, period = 0;
  
  for (size_t i = length; i > 0; i--) {

    if (string[i] == 46 && string[i + 1] >= 48 && string[i + 1] <= 57) {
      period++;
    }
    
    if (string[i - 1] == 45 && string[i] >= 48 && string[i] <= 57) {
      negative++;
    }
    
    if (string[i - 1] >= 48 && string[i - 1] <= 57) {
      integer += pow(10, count) * (string[i - 1] - 48);
      count++;
    }
    if (string[i - 1] >= 48 && string[i - 1] <= 57 && (string[i] < 48 || string[i] > 57)) {
      *Ptr = &string[i];
    }    

  }
  
  if (negative != 0) {
    integer *= -1;
  }

  if (period == 0) {

    if (fabs(integer) <= 2147483647) {
      return integer;
    }
    else {
      return 0;
    }
  }
  else {
    return 0;
  }
}

unsigned long int strToUL(char *string, int length, char** Ptr)
{
  int negative = 0, count = 0, integer = 0, period = 0;

  for (size_t i = length; i > 0; i--) {

    if (string[i] == 46 && string[i + 1] >= 48 && string[i + 1] <= 57) {
      period++;
    }    
    
    if (string[i - 1] == 45 && string[i] >= 48 && string[i] <= 57) {
      negative++;
    }
    
    if (string[i - 1] >= 48 && string[i - 1] <= 57) {
      integer += pow(10, count) * (string[i - 1] - 48);
      count++;
    }

    if (string[i - 1] >= 48 && string[i - 1] <= 57 && (string[i] < 48 || string[i] > 57)) {
      *Ptr = &string[i];
    }
  }

  if (negative != 0) {
    integer *= -1;
  }

  if (period == 0) {

    if (negative == 0) {
      return integer;      
    }
    else {
      return 0;
    }
  }
  else {
    return 0;
  }  
}
