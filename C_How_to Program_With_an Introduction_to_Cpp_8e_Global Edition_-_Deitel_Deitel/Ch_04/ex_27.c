#include <stdio.h>

int main(void)
{

  int count = 0;
  puts("\nSide #1\t\tSide #2\t\tSide");
  puts("\n****************************************\n");
  
  for (unsigned int side1 = 1; side1 <= 500; side1++) {

    for (unsigned int side2 = 1; side2 <= 500; side2++) {

      for (unsigned int side3 = 1; side3 <= 500; side3++) {

	if (count == 0) {
	  
	  if (side1 * side1 == side2 * side2 + side3 * side3) {
	    int min, mid, max;
	    
	    max = side1;
	    if (side1 > side2) {
	      if (side1 > side3) {
		if (side2 > side3) {
		  max = side1;
		  mid = side2;
		  min = side3;
		}
		else{
		  max = side1;
		  mid = side3;
		  min = side2;
		}
	      }
	      else {
		max = side3;
		mid = side1;
		min = side2;
	      }
	    }
	    else {
	      if (side2 > side3) {
		if (side3 > side1) {
		  max = side2;
		  mid = side3;
		  min = side1;
		}
		else {
		  max = side2;
		  mid = side1;
		  min = side3;	 
		}
	      }
	      else {
		max = side3;
		mid = side2;
		min = side1;      
	      }
	    }
	    printf("%d\t\t%d\t\t%d\t\t\n", min, mid, max);
	    count++;
	  }
	}
      }
    }
    count = 0;
  }
}


