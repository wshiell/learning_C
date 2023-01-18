#include <stdio.h>

int main(void)
{
  int decimal;

  puts("Decimal to Roman Numeral Conversion Program (type -1 to quit):");
  puts("Enter a decimal number:");
  scanf("%d", &decimal);

  while (decimal != -1) {
    int digit1 = (decimal / 100);
    int digit2 = (decimal % 100) / 10;
    int digit3 = decimal % 10;
    printf("%s", "Roman Numeral equivalent is: ");
    switch (digit1) {
    case 1:
      printf("%s", "C");
      break;
    }

    switch (digit2) {
    case 1:
      printf("%s", "X");
      break;
    case 2:
      printf("%s", "XX");
      break;
    case 3:
	printf("%s", "XXX");
      break;
    case 4:
      printf("%s", "XL");
      break;
    case 5:
      printf("%s", "L");
      break;
    case 6:
      printf("%s", "LX");
      break;
    case 7:
      printf("%s", "LXX");
      break;
    case 8:
      printf("%s", "LXXX");
      break;
    case 9:
      printf("%s", "LXC");
      break;
    }
    
    switch (digit3) {
    case 1:
      printf("%s", "I");
      break;
    case 2:
      printf("%s", "II");
      break;
    case 3:
	printf("%s", "III");
      break;
    case 4:
      printf("%s", "IV");
      break;
    case 5:
      printf("%s", "V");
      break;
    case 6:
      printf("%s", "VI");
      break;
    case 7:
      printf("%s", "VII");
      break;
    case 8:
      printf("%s", "VIII");
      break;
    case 9:
      printf("%s", "IX");
      break;
    }
    puts("\nEnter a decimal number (-1 to quit):");
    scanf("%d", &decimal);
  }
}
