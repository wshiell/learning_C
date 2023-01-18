#include <stdio.h>

int main(void)
{
  FILE *mastPtr, *transPtr;

  if ((mastPtr = fopen("master.dat", "w")) == NULL) {
    puts("File could not be opened.");
  }
  else {

    fprintf(mastPtr, "%d %s %s %lf\n", 100, "Alan", "Jones", 348.17);
    fprintf(mastPtr, "%d %s %s %lf\n", 200, "Mary", "Smith", 27.19);
    fprintf(mastPtr, "%d %s %s %lf\n", 300, "Sam", "Sharp", 0.00);
    fprintf(mastPtr, "%d %s %s %lf\n", 600, "Suzy", "Green", 0.00);
    fprintf(mastPtr, "%d %s %s %lf\n", 700, "Quentin", "Tanker", 141.11);
    fprintf(mastPtr, "%d %s %s %lf\n", 800, "Werner", "Braun", 145.32);
    fprintf(mastPtr, "%d %s %s %lf\n", 900, "Lloyd", "Ellis", -122.32);
    fprintf(mastPtr, "%d %s %s %lf\n", 1000, "Kevin", "Zepplin", 223.12);
  }

  fclose(mastPtr);

  if ((transPtr = fopen("transaction.dat", "w")) == NULL) {
    puts("File could not be opened.");
  }
  else {

    fprintf(transPtr, "%d %lf\n", 100, 27.14);
    fprintf(transPtr, "%d %lf\n", 200, 62.11);
    fprintf(transPtr, "%d %lf\n", 200, 100.56);
    fprintf(transPtr, "%d %lf\n", 500, -24.13);
    fprintf(transPtr, "%d %lf\n", 700, 1.43);
    fprintf(transPtr, "%d %lf\n", 700, 1004.23);
    fprintf(transPtr, "%d %lf\n", 1000, -147.23);
    fprintf(transPtr, "%d %lf\n", 11000, 8.47);
  }

  fclose(transPtr);
}
