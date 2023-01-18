#include <stdio.h>

int main(void)
{
  unsigned int  productNumber = 0, quantitySold;
  float retailPrice, totalRetailValue = 0;
  
  for (unsigned int day = 1; day <= 7; day++) {
    switch (day) {
      case 1:
	printf("Monday:\n");
	break;
      case 2:
	printf("Tuesday:\n");
	break;
      case 3:
	printf("Wednesday:\n");
	break;
      case 4:
	printf("Thursday:\n");
	break;
      case 5:
	printf("Friday:\n");
	break;
      case 6:
	printf("Saturday:\n");
	break;
      case 7:
	printf("Sunday:\n");
	break;
    }
    while (productNumber != -1) {
      puts("Enter product number (-1 to quit)");
      scanf("%u", &productNumber);
      if (productNumber == -1) {
	break;
      }
      puts("Enter quantity sold:");
      scanf("%u", &quantitySold);

      switch (productNumber) {

      case 1:
	retailPrice = 2.98;
	break;
      case 2:
	retailPrice = 4.50;
	break;
      case 3:
	retailPrice = 9.98;
	break;
      case 4:
	retailPrice = 4.49;
	break;
      case 5:
	retailPrice = 6.87;
	break;
      }

      totalRetailValue += retailPrice * quantitySold;
    }
    productNumber = 0;
  }
  printf("Total retail value for last week is: $%.2f\n", totalRetailValue);
}
