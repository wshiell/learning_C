#include <stdio.h>

int main(void)
{
  FILE *dtPtr;
  char *data;
  char *dataTypes[13] = { "char", "unsigned char", "short int", "unsigned short int",
			  "int", "unsigned int", "long int", "unsigned long int",
			  "float", "double", "long double" };
  int sizes;
  int typeSizes[13] = { sizeof(char), sizeof(unsigned char), sizeof(short int),
 		        sizeof(unsigned short int), sizeof(int), sizeof(unsigned int),
		        sizeof(long int), sizeof(unsigned long int),
		        sizeof(float), sizeof(double), sizeof(long double) };
		       
  if ((dtPtr = fopen("datasize.dat", "wb+")) == NULL) {
    puts("File could not be opened.");
  }
  else {
    for (unsigned int i = 0; i < 11; ++i) {
      fwrite(&dataTypes[i], sizeof(dataTypes[i]), 1, dtPtr);
      fwrite(&typeSizes[i], sizeof(typeSizes[i]), 1, dtPtr);      
    }

    fseek(dtPtr, 0, SEEK_SET);

    printf("%-22s%4s\n", "Data type", "Size");
    
    for (unsigned int i = 0; i < 11; ++i) {
      fread(&data, sizeof(data), 1, dtPtr);
      fread(&sizes, sizeof(sizes), 1, dtPtr);

      printf("%-22s%4d\n", data, sizes);
      
    }
  }

  fclose(dtPtr);
}
