#include <stdio.h>

void printLetters(int digits[7], char *number[8], FILE * phonePtr, unsigned int gridSize[8]);
void readNumbers(unsigned int digits[7], FILE * phonePtr, unsigned int gridSize[8]);

int main(void)
{
  FILE *phonePtr;
  
  char two[4] = { 'A', 'B', 'C', '\0' };
  char three[4] = { 'D', 'E', 'F', '\0' };
  char four[4] = { 'G', 'H', 'I', '\0' };
  char five[4] = { 'J', 'K', 'L', '\0' };
  char six[4] = { 'M', 'N', 'O', '\0' };
  char seven[5] = { 'P', 'Q', 'R', 'S', '\0' };
  char eight[4] = { 'T', 'U', 'V', '\0' };
  char nine[5] = { 'W', 'X', 'Y', 'Z', '\0' };
  char *number[8];
  char *twoPtr, *threePtr, *fourPtr, *fivePtr, *sixPtr, *sevenPtr, *eightPtr, *ninePtr;
  unsigned int digits[7], gridSize[8] = { 3, 3, 3, 3, 3, 4, 3, 4 }, phoneNumber;

  if ((phonePtr = fopen("phoneNumbers.dat", "wb+")) == NULL) {
    puts("File cannot be opened.");
  }
  else {
    twoPtr = &two[0];
    threePtr = &three[0];
    fourPtr = &four[0];
    fivePtr = &five[0];
    sixPtr = &six[0];
    sevenPtr = &seven[0];
    eightPtr = &eight[0];
    ninePtr = &nine[0];
    
    number[0] = twoPtr;
    number[1] = threePtr;
    number[2] = fourPtr;
    number[3] = fivePtr;
    number[4] = sixPtr;
    number[5] = sevenPtr;
    number[6] = eightPtr;
    number[7] = ninePtr;

    puts("Enter a seven-digit number:");
    scanf("%u", &phoneNumber);

    digits[0] = phoneNumber / 1000000;
    digits[1] = phoneNumber % 1000000 / 100000;
    digits[2] = phoneNumber % 100000 / 10000;
    digits[3] = phoneNumber % 10000 / 1000;
    digits[4] = phoneNumber % 1000 / 100;
    digits[5] = phoneNumber % 100 / 10;
    digits[6] = phoneNumber % 10;

    printLetters(digits, number, phonePtr, gridSize);
    readNumbers(digits, phonePtr, gridSize);
  }

  fclose(phonePtr);
}

void printLetters(int digits[7], char *number[8], FILE * phonePtr, unsigned int gridSize[8])
{
  for (unsigned int i = 0; i < gridSize[digits[0] - 2]; ++i) {

    for (unsigned int j = 0; j < gridSize[digits[1] - 2]; ++j) {

      for (unsigned int k = 0; k < gridSize[digits[2] - 2]; ++k) {

	for (unsigned int l = 0; l < gridSize[digits[3] - 2]; ++l) {

	  for (unsigned int m = 0; m < gridSize[digits[4] - 2]; ++m) {

	    for (unsigned int n = 0; n < gridSize[digits[5] - 2]; ++n) {

	      for (unsigned int o = 0; o < gridSize[digits[6] - 2]; ++o) {

		/* for (unsigned int p = 0; p < gridSize[digits[7] - 1]; ++p) { */

		  fwrite(&number[digits[0] - 2][i], sizeof(char), 1, phonePtr);
		  fwrite(&number[digits[1] - 2][j], sizeof(char), 1, phonePtr);
		  fwrite(&number[digits[2] - 2][k], sizeof(char), 1, phonePtr);
		  fwrite(&number[digits[3] - 2][l], sizeof(char), 1, phonePtr);
		  fwrite(&number[digits[4] - 2][m], sizeof(char), 1, phonePtr);
		  fwrite(&number[digits[5] - 2][n], sizeof(char), 1, phonePtr);
		  fwrite(&number[digits[6] - 2][o], sizeof(char), 1, phonePtr);
		/*   fwrite(&number[digits[6] - 2][p], sizeof(char), 1, phonePtr); */
		/* } */
	      }
	    }
	  }
	}
      }
    }
  }
}

void readNumbers(unsigned int digits[7], FILE * phonePtr, unsigned int gridSize[8])
{
  char letter;
  unsigned int totalNumbers;

  totalNumbers = gridSize[digits[0] - 2] * gridSize[digits[1] - 2] *
    gridSize[digits[2] - 2] * gridSize[digits[3] - 2] *
    gridSize[digits[4] - 2] * gridSize[digits[5] - 2] *
    gridSize[digits[6] - 2] * 7;
   
  fseek(phonePtr, 0, SEEK_SET);

  for (size_t i = 0; i < totalNumbers; ++i) {

    fread(&letter, sizeof(char), 1, phonePtr);
    printf("%c", letter);

    if ((i + 1) % 7 == 0) {
      printf("%s", " ");
    }

    if ((i + 1) % 182 == 0) {
      puts("");
    }
  }
  puts("");
}
