#include <stdio.h>
#include <string.h>

typedef struct {
  unsigned int record;
  char tool[30];
  unsigned int quantity;
  double price;
} hardware;

void menu(FILE *fPtr, hardware *toolsPtr);
void initialiseRecords(FILE * fPtr, hardware *toolsPtr);
void inputTool(FILE * fPtr, hardware *toolsPtr);
void printList(FILE * fPtr, hardware *toolsPtr);
void deleteRecord(FILE * fPtr, hardware *toolsPtr);

int main(void)
{
  
  FILE *fPtr;
  hardware tools = { 0, "", 0, 0.0 }, *toolsPtr;
  toolsPtr = &tools;

  if ((fPtr = fopen("hardware.dat", "wb+")) == NULL) {
    puts("File cannot be opened.") ;
  }
  else {
    menu(fPtr, toolsPtr);
  }

  fclose(fPtr);
}

void menu(FILE *fPtr, hardware *toolsPtr)
{
  unsigned int choice;
  
  printf("\n%s\n\n%s\n\n%s\n%s\n%s\n%s\n%s\n\n%s",
	 "** Hardware Inventory Program **", "    Enter a menu option:",
	 "1 - Initialise the record file.",
	 "2 - Add a record to the file.",
	 "3 - Delete a record from the file.",
	 "4 - Print the current inventory",
	 "5 - Quit the program.", "> ");

  scanf("%u", &choice);

  while (choice != 5) {

    switch (choice) {
    case 1:
      initialiseRecords(fPtr, toolsPtr);
      break;
    case 2:
      inputTool(fPtr, toolsPtr);
      break;
    case 3:
      deleteRecord(fPtr, toolsPtr);
      break;
    case 4:
      printList(fPtr, toolsPtr);
      break;
    default:
      puts("Incorrect entry.");
      break;
    }

    printf("\n%s\n\n%s\n\n%s\n%s\n%s\n%s\n%s\n\n%s",
	   "** Hardware Inventory Program **", "    Enter a menu option:",
	   "1 - Initialise the record file.",
	   "2 - Add a record to the file.",
	   "3 - Delete a record from the file.",
	   "4 - Print the current inventory",
	   "5 - Quit the program.", "> ");

    scanf("%u", &choice);
  }
}

/* void initialiseRecords(FILE * fPtr, hardware *toolsPtr) */
/* { */
/*   for (unsigned int i = 1; i <= 100; ++i) { */

/*     toolsPtr->record = i; */
/*     printf("*%d", toolsPtr->record); */
/*     fwrite(&toolsPtr, sizeof(hardware), 1, fPtr); */
/*   } */
/* } */

/* void inputTool(FILE * fPtr, hardware *toolsPtr) */
/* { */
/*   ; */
/* } */

/* void deleteRecord(FILE * fPtr, hardware *toolsPtr) */
/* { */
/*   ; */
/* } */

/* void printList(FILE * fPtr, hardware *toolsPtr) */
/* { */
  
/*   fseek(fPtr, 0, SEEK_SET); */

/*   printf("\n%15s%20s%10s%10s\n", */
/* 	 "Record #", "Tool Name", "Quantity", "Price"); */

/*   while (!feof(fPtr)) { */

/*     fread(&toolsPtr, sizeof(hardware), 1, fPtr); */
/*     printf("\n%15u%20s%10u%10.2lf", */
/* 	   toolsPtr->record, toolsPtr->tool, */
/* 	   toolsPtr->quantity, toolsPtr->price); */

/*   } */
/* } */

void initialiseRecords(FILE * fPtr, hardware *toolsPtr)
{
  fseek(fPtr, 0, SEEK_SET);

  for (unsigned int i = 0; i < 10; ++i) {

    char s[30] = "";
    sscanf(s, "%s", toolsPtr->tool);

    toolsPtr->record = i + 1;
    toolsPtr->quantity = 0;
    toolsPtr->price = 0.0;
    
    fwrite(toolsPtr, sizeof(hardware), 1, fPtr);
  }
}
void inputTool(FILE * fPtr, hardware *toolsPtr)
{
  printf("\n%s\n\n%s", "Enter record # (-1 to quit):", "> ");
  scanf("%u", &toolsPtr->record);

  while(toolsPtr->record != -1) {

    fseek(fPtr, (toolsPtr->record - 1) * sizeof(hardware), SEEK_SET);
    fread(toolsPtr, sizeof(hardware), 1, fPtr);
    getchar();

    if (!strcmp(toolsPtr->tool, "")) {

      printf("\n%s\n\n%s", "Enter tool name:", "> ");
      fgets(toolsPtr->tool, 30, stdin);

      toolsPtr->tool[strlen(toolsPtr->tool) - 1] = '\0';

      printf("\n%s\n\n%s", "Enter quantity:", "> ");
      scanf("%u", &toolsPtr->quantity);

      printf("\n%s\n\n%s", "Enter price:", "> ");
      scanf("%lf", &toolsPtr->price);

      fseek(fPtr, (toolsPtr->record - 1) * sizeof(hardware), SEEK_SET);
      fwrite(toolsPtr, sizeof(hardware), 1, fPtr);
    }
    else {
      getchar();
      puts("There is an existing record with this number.");
      fseek(fPtr, 0, SEEK_SET);
    }
    printf("\n%s\n\n%s", "Enter record (-1 to quit):", "> ");
    scanf("%u", &toolsPtr->record);
  }
}

void printList(FILE * fPtr, hardware *toolsPtr)
{
  fseek(fPtr, 0, SEEK_SET);
  printf("\n%-10s%-30s%-10s%-10s\n\n", "Record #", "Tool Name", "Quantity", "Price");

  for (unsigned int i = 0; i < 10; ++i) {

    fread(toolsPtr, sizeof(hardware), 1, fPtr);
    printf("%-10u%-30s%-10u$%-10.2lf\n",
	   toolsPtr->record, toolsPtr->tool, toolsPtr->quantity, toolsPtr->price);
  }
}

void deleteRecord(FILE * fPtr, hardware *toolsPtr)
{
  printf("\n%s\n\n%s", "Enter the record number of the tool to delete:", "> ");
  scanf("%u", &toolsPtr->record);

  fseek(fPtr, (toolsPtr->record - 1) * sizeof(hardware), SEEK_SET);

  fwrite(toolsPtr, sizeof(hardware), 1, fPtr);
}
