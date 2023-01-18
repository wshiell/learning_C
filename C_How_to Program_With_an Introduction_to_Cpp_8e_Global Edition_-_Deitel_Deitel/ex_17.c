#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  float currentBalance;
  int customer, accountNumber, creditLimit;

  srand(time(NULL));
  
  for (unsigned int customer = 1; customer <= 3; customer) {
    printf("Customer #%u\n\n", customer);

    accountNumber = 1000000000 + rand() % 1000000000;
    printf("Account Number: #%u\n", accountNumber);

    creditLimit = 1000 + ((rand() % 10000) / 1000) * 1000;
    printf("Previous Credit Limit: $%u\n", creditLimit);

    creditLimit /= 2;
    
    printf("New credit limit is: $%u\n", creditLimit);

    currentBalance = rand() % 10000;
    printf("Current Balance: $%.2f\n\n", currentBalance);

    if (creditLimit < currentBalance) {
      printf("*****Credit Limit exceeded. Contact customer*****.\n\n");
    }
    customer++;
  }
}
