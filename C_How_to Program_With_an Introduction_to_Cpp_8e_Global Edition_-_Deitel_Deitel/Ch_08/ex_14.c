#include <stdio.h>
#include <string.h>
#define SIZE 15

int main(void)
{
  char phoneNumber[SIZE];
  char *areaCode, *threeDigits, *fourDigits;
  char *newNumber;
  
  puts("\nInput a telephone number in the form (555) 555-5555:");
  puts("  [(555) - area code, 555-5555 - localphone number]\n");
  printf("%s", " > ");
  fgets(phoneNumber, SIZE, stdin);

  areaCode = strtok(phoneNumber, "() -");
  threeDigits = strtok(NULL, "() -");
  fourDigits = strtok(NULL, "() -");

  strcat(areaCode, threeDigits);
  strcat(areaCode, fourDigits);

  newNumber = areaCode;
  
  printf("\nConcatenated Numbers: %s\n\n", newNumber); 
}
