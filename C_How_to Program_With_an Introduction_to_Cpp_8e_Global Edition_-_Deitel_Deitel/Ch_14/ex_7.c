#include <stdio.h>

void reverse(FILE * inputPtr, FILE * outputPtr);
  
int main(int argc, char *argv[])
{
  if (argc != 3) {
    puts("Usage: mycopy infile outfile");
  }
  else {
     FILE * inputPtr;

    if ((inputPtr = fopen(argv[1], "r")) != NULL) {

      FILE *outputPtr;
      
      if ((outputPtr = fopen(argv[2], "w")) != NULL) {

	reverse(inputPtr, outputPtr);
	
	fclose(outputPtr);
      }
      else {
	printf("%s%s%s\n", "File \"", argv[2], "\" could not be opened.");      
      }
      
      fclose(inputPtr);
    }
    else {
      printf("%s%s%s\n", "File \"", argv[1], "\" could not be opened.");
    }
  }
}

void reverse(FILE * inputPtr, FILE * outputPtr)
{
  int c;

  if ((c = fgetc(inputPtr)) != EOF) {
    reverse(inputPtr, outputPtr);
    fputc(c, outputPtr);
  }
}
