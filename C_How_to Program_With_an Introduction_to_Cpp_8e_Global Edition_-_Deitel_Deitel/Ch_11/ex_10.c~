#include <stdio.h>

int main(void)
{
  FILE *ofPtr, *tfPtr, *nfPtr;

  int accountNum, transNum, match;
  char firstName[15], lastName[15];
  double oldBalance, dollarAmount;
  
  if((ofPtr = fopen("master.dat", "r")) == NULL) {
    puts("Master record cannot be opened.");
  }
  else if ((tfPtr = fopen("transaction.dat", "r")) == NULL) {
    puts("Transaction record cannot be opened.");
  }
  else if ((nfPtr = fopen("newmast.dat", "w")) == NULL) {
    puts("File cannot be opened.");
  }
  else {
    fscanf(ofPtr, "%d%s%s%lf", &accountNum, firstName, lastName, &oldBalance);

    while (!feof(ofPtr)) {

      match = 0;
      
      fscanf(tfPtr, "%d%lf", &transNum, &dollarAmount);

      while (!feof(tfPtr)) {

    	if (accountNum == transNum) {
    	  fprintf(nfPtr, "%d %s %s %lf\n", accountNum, firstName, lastName, oldBalance + dollarAmount);
    	  match++;
    	}

        fscanf(tfPtr, "%d%lf", &transNum, &dollarAmount);
      }

      if (match == 0) {
        fprintf(nfPtr, "%d %s %s %lf\n", accountNum, firstName, lastName, oldBalance);
      }
      
      rewind(tfPtr);
      fscanf(ofPtr, "%d%s%s%lf", &accountNum, firstName, lastName, &oldBalance);
    }
    
    rewind(ofPtr);
    rewind(tfPtr);
    
    fscanf(tfPtr, "%d%lf", &transNum, &dollarAmount);

    while (!feof(tfPtr)) {

      match = 0;
      
      fscanf(ofPtr, "%d%s%s%lf", &accountNum, firstName, lastName, &oldBalance);

      while (!feof(ofPtr)) {

    	if (accountNum == transNum) {
	  match++;
	}
	
    	fscanf(ofPtr, "%d%s%s%lf", &accountNum, firstName, lastName, &oldBalance);
      }

      if (match == 0) {
	printf("Unmatched transaction record for account #%d\n", transNum);
      }

      rewind(ofPtr);
      fscanf(tfPtr, "%d%lf", &transNum, &dollarAmount);
    }

    rewind(ofPtr);
    
    fclose(ofPtr);
    fclose(tfPtr);
    fclose(nfPtr);
  }
}
