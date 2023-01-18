#include <stdio.h>
#include <string.h>

int main(void)
{
  FILE * inputPtr;

  if ((inputPtr = fopen("input.txt", "w")) != NULL) {

    int c;
      
    while ((c = getchar()) != '\n') {
      fputc(c, inputPtr);
    }
  }
  else {
    puts("File cannot be accessed.");
  }

  fclose(inputPtr);
}
