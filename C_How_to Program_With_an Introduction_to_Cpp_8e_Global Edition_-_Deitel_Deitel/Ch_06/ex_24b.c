#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 64 // Sets the number of attempted moves the knight must make per tour

// Function which moves knight for each value of 'move'

int moveKnight(int move, int position[], int board[][8]);

// Function prints the board after moves have been made

void printBoard(int board[][8], int position[]);

// Function generates a random array of eight unique numbers

void generateRandom(int randomNumber[]);

// Begin function 'main'

int main(void)
{
  srand(time(NULL));

  int max = 0;
  int counter = 0;
  int valid = 0; // Indicates whether the move made was valid
  int board[8][8] = {0}; // Declare and initialise array 'board'
  int position[2]; // Declare array describing knight's position
  
  position[0] = 4; // Initial row position of knight
  position[1] = 4; // Initial column position of knight
  board[position[0]][position[1]] = 1; // Declare starting position of knight

  for (int move = 1; move < SIZE; move++) { // Move the knight

    valid = moveKnight(move, position, board); // Call function 'moveKnight
    max = board[position[0]][position[1]];

    if (max < SIZE && move == SIZE - 1) {
      printf("\nTour terminated at move #%d\n", max);
      break;
    }

    if (max == SIZE) {
      puts("\nSuccessful Tour!");
    }
  }
  
  printBoard(board, position); // Call function 'printBoard'
} // End function 'main'


// Begin function 'moveKnight'

int moveKnight(int move, int position[], int board[][8])
{
  int counter = 0; // Declare variable to to count number of invalid moves
  int currentRow, currentColumn; // Declare current row & column of knight
  int moveNumber; // Declare which 'type' of move is being made
  int randomNumber[8] = {0}; // Declare array 'randomNumber'
  int horizontal[8] = {2, 1, -1, -2, -2, -1, 1, 2}; // Declare array 'horizontal'
  int vertical[8] = {-1, -2, -2, -1, 1, 2, 2, 1}; // Declaire array 'vertical'

  /* printf("\nMove Number: %d\t", moveNumber); */
  /* printf("(%d, %d)\n", horizontal[moveNumber], vertical[moveNumber]); */
  
  // Populate array 'randomNumber', to be used to ensure moves are not duplicated

  generateRandom(randomNumber);

  for (int count = 0; count < 8; count++) {
    moveNumber = randomNumber[count];
  
    currentRow = position[0]; // Assign current row position to knight
    currentColumn = position[1]; // Assign current column position to knight
  
    currentRow += horizontal[moveNumber]; // Change row position by moving knight
    currentColumn += vertical[moveNumber]; // Change column position by moving knight

    // Ensure that the knight is not moved off of the board

    if (currentRow < 0 || currentRow > 7 || currentColumn < 0 || currentColumn > 7) {
      continue;
    }
    else {

      // Ensure the knight does not move back to a previously occupied square
    
      if (board[currentRow][currentColumn] != 0) {
      }
      else {

	position[0] += horizontal[moveNumber]; // Assign new row position
	position[1] += vertical[moveNumber]; // Assign new column position
	board[position[0]][position[1]] = move + 1; // Change board after last move
	return 1;
      }
    }
  }
} //End function 'moveKnight'

// Begin function 'printBoard'

void printBoard(int board[][8], int position[])
{
  // Print final position of knight
  
  printf("\nKnight's position: (%d, %d)\n\n", position[0] + 1, position[1] + 1);

  puts("");
  
  // Print top border
  
  for (int count = 0; count < 10; count++) {

    if (count > 0 && count < 9) {
      printf("%3d", count);
    }
    else {
      printf("%3s", " ");
    }
  }
  puts("\n");


  // Print board with moves indicated by number
  
  for (int row = 0; row < 8; row++) {

    printf("%3d", row + 1); // Print left border
    
    for (int column = 0; column < 8; column++) {

      // Print move values
      
      if (board[row][column] != 0) {
	printf("%3d", board[row][column]);
      }
      else {
	printf("%3s", ".");
      }
    }
    printf("%3d\n\n", row + 1); // Print right border
  }

  // Print bottom border
  
  for (int count = 0; count < 10; count++) {

    if (count > 0 && count < 9) {
      printf("%3d", count);
    }
    else {
      printf("%3s", " ");
    }
  }
  puts("\n");
} // End function 'printBoard'

// Begin function 'generateRandom'

void generateRandom(int randomNumber[])
{
  int random; // Random number generated

  // Generate random numbers and fill array 'randomNumber'
  
  for (int counter = 0; counter <  8; counter++) {
    random = 1 + rand() % 8; // Assign random number between 1-8 to 'random'

    // Generate new random numbers if 'random' has already appeared in
    // randomNumbers, or assign 'random' to appropriate array element
    
    while (random == randomNumber[0] || random == randomNumber[1]
	 || random == randomNumber[2] || random == randomNumber[3]
	 || random == randomNumber[4] || random == randomNumber[5]
         || random == randomNumber[6]) {
      random = 1 + rand() % 8;
    }
    randomNumber[counter] = random;
  }

  // Shift array 'randomNumbers' to the range 0-7
  
  for (int count = 0; count < 8; count++) {
    randomNumber[count] = randomNumber[count] - 1;
  }
} // End function 'generateRandom'
