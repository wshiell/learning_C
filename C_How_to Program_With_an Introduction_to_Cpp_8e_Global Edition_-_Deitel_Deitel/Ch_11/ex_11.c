#include <stdio.h>

struct person {
  char lastName[15];
  char firstName[15];
  char age[4];
};

int main(void)
{
  FILE *naPtr;
  unsigned int record;
  struct person ind = { "unassigned", "unassigned", "0" };

  //Open file
  
  if ((naPtr = fopen("nameage.dat", "rb+")) == NULL) {
    puts("File cannot be opened.");
  }
  else{

    //Initialise file
    
    for (unsigned int i = 1; i <= 10; ++i) {

      fwrite(&ind, sizeof(struct person), 1, naPtr);
    }
    
    //Write ten records

    fseek(naPtr, (1 - 1) * sizeof(struct person), SEEK_SET);
    
    for (unsigned int i = 1; i <= 2; ++i) {

      puts("Enter first name, last name and age:");
      fscanf(stdin, "%15s%15s%4s", ind.firstName, ind.lastName, ind.age);

      fwrite(&ind, sizeof(struct person), 1, naPtr);
    }

    //Update a record

    fseek(naPtr, (1 - 1) * sizeof(struct person), SEEK_SET);    
    
    puts("Enter record number:");
    scanf("%u", &record);

    fseek(naPtr, (record - 1) * sizeof(struct person), SEEK_SET);

    fread(&ind, sizeof(struct person), 1, naPtr);

    if (ind.firstName == "unassigned") {
      puts("No data.");
    }
    else {
      puts("Enter first name, last name and age:");
      fscanf(stdin, "%15s%15s%4s", ind.firstName, ind.lastName, ind.age);
	 
      fwrite(&ind, sizeof(struct person), 1, naPtr);
    }

    //Delete a record

    fseek(naPtr, (1 - 1) * sizeof(struct person), SEEK_SET);    
    
    puts("Enter record number:");
    scanf("%u", &record);

    fseek(naPtr, (record - 1) * sizeof(struct person), SEEK_SET);

    fread(&ind, sizeof(struct person), 1, naPtr);

    if (ind.firstName == "unassigned") {
      puts("No data.");
    }
    else {
      fwrite(&ind, sizeof(struct person), 1, naPtr);
    }
  }
}
