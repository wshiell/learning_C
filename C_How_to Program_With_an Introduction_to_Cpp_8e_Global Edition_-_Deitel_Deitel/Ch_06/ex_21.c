#include <stdio.h>

int main(void)
{
  int rowsA, rowsB, columnsA, columnsB;

  // Enter dimensions of matrices
  
  puts("Enter rows in A:");
  scanf("%d", &rowsA);

  puts("Enter columns in A:");
  scanf("%d", &columnsA);

  rowsB = columnsA;
  
  puts("Enter columns in B:");
  scanf("%d", &columnsB);

  // Define arrays
  
  int A[rowsA][columnsA];
  int B[rowsB][columnsB];
  int C[rowsA][columnsB];

  // Prompt user to enter elements of matrix 'A'
  
  for (int rows = 0; rows < rowsA; rows++) {

    for (int columns = 0; columns < columnsA; columns++) {
      printf("Enter %d x %d entry of matrix A:", rows + 1, columns + 1);
      scanf("%d", &A[rows][columns]);
    }
  }

  // Prompt user to enter elements of matrix 'B'  
  
  for (int rows = 0; rows < rowsB; rows++) {

    for (int columns = 0; columns < columnsB; columns++) {
      printf("Enter %d x %d entry of matrix B:", rows + 1, columns + 1);
      scanf("%d", &B[rows][columns]);
    }
  }

  // Print matrix 'A'
  
  puts("A = \n");

  for (int rows = 0; rows < rowsA; rows++) {

    for (int columns = 0; columns < columnsA; columns++) {
        printf("%-3d", A[rows][columns]);	
    }
    puts("");
  }

  // Print matrix 'B'
  
  puts("\nB = \n");

  for (int rows = 0; rows < rowsB; rows++) {

    for (int columns = 0; columns < columnsB; columns++) {
        printf("%-3d", B[rows][columns]);	
    }
    puts("");
  }

  // Initialise matrix 'C' (A x B) to zero

  puts("\nA x B = \n");

  for (int row = 0; row < rowsA; row++) {

    for (int column = 0; column < columnsB; column++) {
      C[row][column] = 0;
    }
  }

  // Multiply 'A' by 'B'
  
  for (int row = 0; row < rowsA; row++) {

    for (int shared = 0; shared < columnsA; shared++) {

      for (int column = 0; column < columnsB; column++) {
  	C[row][column] += A[row][shared] * B[shared][column];
      }
    }
  }

  // Print matrix 'C'

  for (int rows = 0; rows < rowsA; rows++) {

    for (int columns = 0; columns < columnsB; columns++) {
        printf("%-3d", C[rows][columns]);
    }
    puts("");
  }
}
