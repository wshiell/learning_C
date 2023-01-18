#include <stdio.h>

int main(void) {
  unsigned int newRow = 0;

  for (unsigned int prime = 1; prime <= 1000; prime++) {

    if (prime == 2) {
      printf("%u\t", prime);
      newRow++;
    }
    
    else {

      if (prime == 1) {
	printf("%s", "");
      }

      else {
        unsigned int tally = 0;

	for (unsigned int counter = 1; counter <= prime; counter++) {
	  
	  if ((prime % counter == 0) && ( prime / counter != prime)) {
	    tally++;
	  }
	}

	if (tally == 1) {
	  printf("%u\t", prime);
	  newRow++;

	  if (newRow % 10 == 0) {
	    puts("");
	  }
	}
	tally = 0;
      }
    }
  }
  puts("");
}
