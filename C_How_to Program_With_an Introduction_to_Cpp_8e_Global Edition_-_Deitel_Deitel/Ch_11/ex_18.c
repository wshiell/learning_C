#include <stdio.h>

struct clientData {
  unsigned int accNum;
  char lastName[15];
  char firstName[10];
  double balance;
};

unsigned int enterChoice(void);
void textFile(FILE *readPtr);
void updateRecord(FILE *fPtr);
void newRecord(FILE *fPtr);
void deleteRecord(FILE *fPtr);
void displayAccounts(FILE *fPtr);

int main(void)
{
  FILE *cfPtr;

  if ((cfPtr = fopen("accounts.dat", "rb+")) == NULL) {
    puts("File could not be opened.");
  }
  else {
    unsigned int choice;

    while ((choice = enterChoice()) != 6) {
      switch (choice) {

      case 1:
	textFile(cfPtr);
	break;
      case 2:
	updateRecord(cfPtr);
	break;
      case 3:
	newRecord(cfPtr);
	break;
      case 4:
	deleteRecord(cfPtr);
	break;
      case 5:
	displayAccounts(cfPtr);
	break;
      default:
	puts("Incorrect choice");
	break;
      }
    }

    fclose(cfPtr);
  }
}

void textFile(FILE *readPtr)
{
  FILE *writePtr;

  if ((writePtr = fopen("accounts.txt", "w")) == NULL) {
    puts("File could not be opened.");
  }
  else {
    rewind(readPtr);
    fprintf(writePtr, "%-6s%-16s%-11s%10s\n",
	    "Acct", "Last Name", "First Name", "Balance");

    while (!feof(readPtr)) {

      struct clientData client = {1, "", "", 0.0};
      int result =
	fread(&client, sizeof(struct clientData), 1, readPtr);

      if (result != 0 && client.accNum != 0) {
	fprintf(writePtr, "%-6d%-16s%-11s%10.2f\n",
	       client.accNum, client.lastName,
	       client.firstName, client.balance);
      }
    }

    fclose(writePtr);
  }
}

void updateRecord(FILE *fPtr)
{
  printf("%s", "Enter account to update (1 - 100): ");
  unsigned int account;
  scanf("%d", &account);

  fseek(fPtr, (account - 1) * sizeof(struct clientData),
	SEEK_SET);

  struct clientData client = {0, "", "", 0.0};

  fread(&client, sizeof(struct clientData), 1, fPtr);

  if (client.accNum == 0) {
    printf("Account #%d has no information.\n", account);
  }
  else {
    printf("%-6d%-16s%-11s%10.2f\n\n",
	   client.accNum, client.lastName,
	   client.firstName, client.balance);

    printf("%s", "Enter charge (+) or payment (-): ");
    double transaction;
    scanf("%lf", &transaction);
    client.balance += transaction;

    printf("%-6d%-16s%-11s%10.2f\n",
	   client.accNum, client.lastName,
	   client.firstName, client.balance);

    fseek(fPtr, (account - 1) * sizeof(struct clientData),
	  SEEK_SET);

    fwrite(&client, sizeof(struct clientData), 1, fPtr);
  }
}

void deleteRecord(FILE *fPtr)
{
  printf("%s", "Enter account to delete (1 - 100): ");
  unsigned int accountNum;
  scanf("%d", &accountNum);

  fseek(fPtr, (accountNum - 1) * sizeof(struct clientData),
	SEEK_SET);

  struct clientData client;

  fread(&client, sizeof(struct clientData), 1, fPtr);

  if (client.accNum == 0) {
    printf("Account #%d has no information.\n", accountNum);
  }
  else {
    fseek(fPtr, (accountNum - 1) * sizeof(struct clientData),
	  SEEK_SET);

    struct clientData blankClient = {0, "", "", 0.0};

    fwrite(&blankClient,
	   sizeof(struct clientData), 1, fPtr);
  }  
}

void newRecord(FILE *fPtr)
{
  printf("%s", "Enter new account number (1 - 100): ");
  unsigned int accountNum;
  scanf("%d", &accountNum);

  fseek(fPtr, (accountNum - 1) * sizeof(struct clientData),
	SEEK_SET);

  struct clientData client = {0, "", "", 0.0};

  fread(&client, sizeof(struct clientData), 1, fPtr);

  if (client.accNum != 0) {
    printf("Account #%d already contains information.\n", client.accNum);
  }
  else {
    printf("%s\n\n%s", "Enter lastname, firstname, balance\n", "> ");
    scanf("%14s%9s%lf", client.lastName, client.firstName,
	  &client.balance);

    client.accNum = accountNum;
    
    fseek(fPtr, (client.accNum - 1) *
	  sizeof(struct clientData), SEEK_SET);

    fwrite(&client,
	   sizeof(struct clientData), 1, fPtr);
  }    
}

unsigned int enterChoice(void)
{

  printf("%s\n%s", "\nEnter your choice\n"
	 "1 - store a formatted text file of accounts called\n"
	 "    \"accounts.txt\" for printing\n"
	 "2 - update an account\n"
	 "3 - add a new account\n"
	 "4 - delete an account\n"
	 "5 - display all accounts\n"
	 "6 - end program\n",
	 "> ");

  unsigned int menuChoice;
  scanf("%u", &menuChoice);
  return menuChoice;
}

void displayAccounts(FILE *fPtr)
{
  struct clientData client;
  
  fseek(fPtr, 0, SEEK_SET);

  printf("\n%-6s%-16s%-11s%10s\n\n",
	 "Acct", "Last Name", "First Name", "Balance");

  while (!feof(fPtr)) {

    int result =
      fread(&client, sizeof(struct clientData), 1, fPtr);

    if (result != 0 && client.accNum != 0) {
      printf("%-6d%-16s%-11s%10.2lf\n",
	     client.accNum, client.lastName, client.firstName,
	     client.balance);
    }
  }
}
