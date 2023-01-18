#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 64 // Sets the number of attempted moves the knight must make per tour
#define TRIALS 2000 // Number of times the tour is attempted

// Funtion that runs TRIAL number of tours

int tour(void);

// Function which moves knight for each value of 'move'

void moveKnight(int move, int position[], int board[][8], int accessibility[][8]);

// Function prints the board after moves have been made

void printBoard(int board[][8], int position[], int max);

// Function generates a random array of eight unique numbers

void generateRandom(int randomNumber[]);

// Function to test whether the Knight's Tour is closed

int testClosed(int start[], int finish[]);

// Functions to control text colour

void red(void); // Red
void blue(void); // Blue
void green(void); // Green
void yellow(void); // Yellow
void reset(void); // Resets colour to default

// Begin function 'main'

int main(void)
{
  srand(time(NULL));

  int closed = 0;
  double percentageClosed;

  for (int count = 0; count < TRIALS; count++) {
    closed += tour();
  }

  percentageClosed = 100 * (float) closed / TRIALS;

  /* yellow(); */
  printf("Percent closed tours: %.2f\n\n", percentageClosed);
} // End function main

// Begin function 'tour'

int tour(void)
{
  int success = 0; // Number of closed tours
  int max = 0; // Declare variable describing largest move recorded per tour attempt
  int start[2]; // Knight's starting position
  int finish[2]; // Knight's finishing position
  int board[8][8] = {0}; // Declare and initialise array 'board'
  int position[2]; // Declare array describing knight's position
  int accessibility[8][8] = {{2, 3, 4, 4, 4, 4, 3, 2}, // Array which displays
			     {3, 4, 6, 6, 6, 6, 4, 3}, // the accessibility of each
			     {4, 6, 8, 8, 8, 8, 6, 4}, // position on the board by
                             {4, 6, 8, 8, 8, 8, 6, 4}, // showing how many squares can
			     {4, 6, 8, 8, 8, 8, 6, 4}, // be reached from any given
			     {4, 6, 8, 8, 8, 8, 6, 4}, // square
			     {3, 4, 6, 6, 6, 6, 4, 3},
       		             {2, 3, 4, 4, 4, 4, 3, 2}};
  
  position[0] = rand() % 8; // Initial row position of knight
  position[1] = rand() % 8; // Initial column position of knight
  board[position[0]][position[1]] = 1; // Declare starting position of knight
  start[0] = position[0];
  start[1] = position[1];
  
  for (int move = 1; move < SIZE; move++) { // Move the knight

    moveKnight(move, position, board, accessibility); // Call function 'moveKnight'
    max = board[position[0]][position[1]]; 

    if (max < SIZE && move == SIZE - 1) {
      /* red(); */
      /* printf("\n   Tour terminated at move #%d\n\n", max); */
      break;
    }

    if (max == SIZE) {
      /* green(); */
      /* puts("\n\tSuccessful Tour!\n"); */
    }
  }

  finish[0] = position[0];
  finish[1] = position[1];

  success = testClosed(start, finish);
  
  /* printBoard(board, position, max); // Call function 'printBoard' */

  return success;
} // End function 'tour'

// Begin function 'moveKnight'

void moveKnight(int move, int position[], int board[][8], int accessibility[][8])
{
  int currentRow, currentColumn; // Declare current row & column of knight
  int moveNumber; // Declare which 'type' of move is being made
  int randomNumber[8] = {0}; // Declare array 'randomNumber'
  int horizontal[8] = {2, 1, -1, -2, -2, -1, 1, 2}; // Declare array 'horizontal'
  int vertical[8] = {-1, -2, -2, -1, 1, 2, 2, 1}; // Declare array 'vertical'
  int min = 9; // Describes the position moved to with the lowest accessibility number
  int testArray[8]; // Array which lists accessibility numbers of potential positions

  // Populate array 'randomNumber', to be used to ensure moves are not duplicated

  generateRandom(randomNumber);

  // Determine if a potential move is valid, and if it is, record the corresponding
  // accesibility number for that move in the array 'testArray'. If the move is not
  // valid, input zero into the array
  
  for (int count = 0; count < 8; count++) {

    moveNumber = randomNumber[count]; // Analyse move 'count' to determine validity
  
    currentRow = position[0]; // Assign current row position to knight
    currentColumn = position[1]; // Assign current column position to knight
  
    currentRow += horizontal[moveNumber]; // Change row position by moving knight
    currentColumn += vertical[moveNumber]; // Change column position by moving knight

    // Ensure that the knight is not moved off of the board

    if (currentRow < 0 || currentRow > 7 || currentColumn < 0 || currentColumn > 7) {
      testArray[count] = 10;
    }
    else {

      // Ensure the knight does not move back to a previously occupied square
    
      if (board[currentRow][currentColumn] != 0) {
        testArray[count] = 11;
      }

      // If move is valid, record accessibility number of the move in position 'count'
      
      else {

	testArray[count] = accessibility[currentRow][currentColumn];
      }
    }
  }

  // Change array 'accessibility' to reflect board changes

  for (int count = 0; count < 8 ; count++) {

    int tempRow = position[0];
    int tempColumn = position[1];
      
    if (testArray[count] != 10) {
      tempRow += horizontal[randomNumber[count]];
      tempColumn += vertical[randomNumber[count]];
      accessibility[tempRow][tempColumn]--;
    }
  }

  // Determine the smallest accessibility number using the valid moves available, 
  // and set the move number to to corresponding move type

  int tempMove1, tempMove2; // Temporary move numbers
  int tempMin1 = 9, tempMin2 = 9; // Temporary minimum accessibility numbers
  int minCounter = 0;
  
  for (int count = 0; count < 8; count++) {

    // If accessibility number is unique and valid
    
    if (testArray[count] < min && testArray[count] != 10) {

      min = testArray[count]; // Set min equal to smallest accessibility number
      moveNumber = randomNumber[count]; // Set moveNumber equal to corresponding move
    }

    // If accessibility number is not unique

    else {

      // Determine the lowest dual sequence of accessibility numbers using the valid moves
      // available and set the move number to to corresponding move type
     
      if (testArray[count] == min) {
  
        tempMin1 = 9, tempMin2 = 9; // Temporary minimum accessibility numbers
	int choice1 = moveNumber, choice2 = randomNumber[count]; // Candidate move numbers
	int testPosition0, testPosition1; // Candidate position values
	int position0, position1; // Positions moved to *from* candidate positions

	// Move knight to candidate position 1
	
	testPosition0 = position[0] + horizontal[choice1];
	testPosition1 = position[1] + vertical[choice1];

	// Determine the position with the smallest accessibility number to which the
	// knight can move from candidate position 1

	for (int count = 0; count < 8; count++) {

	  // Value of positions moved to from candidate position 1
	  
	  position0 = testPosition0 + horizontal[count];
	  position1 = testPosition1 + vertical[count];

	  // Ensure knight is not moved off of the board
	  
	  if (position0 >= 0 && position0 < 8 && position1 >= 0 && position1 < 8) {

	    // Ensure knight doesn't move to a square it's already visited

	    if (board[position0][position1] == 0) {
	    
	      // Determine the lowest accessibility number reachable from candidate position 1
	    	    
	      if (accessibility[position0][position1] < tempMin1) {

		// Set the accessibility value of the position with the lowest value
		// reachable from candidate position 1, and set the temporary move value
		// equal to the move value used to reach this position
	      
		tempMin1 = accessibility[position0][position1];
		tempMove1 = choice1;
	      }
	      else {
		;
	      }
	    }
	    else {
	      ;
	    }
	  }
	  else {
	    ;
	  }
	}

	// Move knight to candidate position 2

	testPosition0 = position[0] + horizontal[choice2];
	testPosition1 = position[1] + vertical[choice2];

	// Determine the position with the smallest accessibiility number to which the
	// knight can move from candidate position 2
	
	for (int count = 0; count < 8; count++) {

	  // Value of positions moved to from candidate position 2
	  
	  position0 = testPosition0 + horizontal[count];
	  position1 = testPosition1 + vertical[count];

	  // Ensure knight is not moved off of the board

	  if (position0 >= 0 && position0 < 8 && position1 >= 0 && position1 < 8) {

	    // Ensure knight doesn't move to a square it's already visited

	    if (board[position0][position1] == 0) {

	      // Determine the lowest accessibility number reachable from candidate position 2

	      if (accessibility[position0][position1] < tempMin2) {

		// Set the accessibility value of the position with the lowest value
		// reachable from candidate position 1, and set the temporary move value
		// equal to the move value used to reach this position

		tempMin2 = accessibility[position0][position1];
		tempMove2 = choice2;
	      }
	      else {
		;
	      }
	    }
	    else {
	      ;
	    }
	  }
	  else {
	    ;
	  }
	}
      }
      else {
	;
      }
    }
  }

  for (int count = 0; count < 8; count++) {

    if (testArray[count] == min) {
      minCounter++;
    }
  }

  if (minCounter != 1) {
  
    if (tempMin1 < tempMin2) {
      min = tempMin1;
      moveNumber = tempMove1;
    }
    else {

      if (tempMin2 < tempMin1 || tempMin1 == tempMin2) {
	min = tempMin2;
	moveNumber = tempMove2;
      }
    }
  }

  if (min != 10) {
    position[0] += horizontal[moveNumber];
    position[1] += vertical[moveNumber];
    board[position[0]][position[1]] = move + 1;
  }
} // End function 'moveKnight'

// Begin function 'printBoard'

void printBoard(int board[][8], int position[], int max)
{
   // Print top border
  
  for (int count = 0; count < 10; count++) {

    if (count > 0 && count < 9) {
      yellow();
      printf("%3d", count);
      reset();
    }
    else {
      printf("%3s", " ");
    }
  }
  puts("\n");

  // Print board with moves indicated by number
  
  for (int row = 0; row < 8; row++) {

    yellow();
    printf("%3d", row + 1); // Print left border
    reset();
    
    for (int column = 0; column < 8; column++) {

      // Print move values

      if (board[row][column] != 0) {

	if (board[row][column] == 1) {
	  green();
	}
	else {

	  if (board[row][column] == max) {
	    red();
	  }
	  else {
	    blue();
	  }
	}
	  printf("%3d", board[row][column]);
	reset();
      }
      else {
	blue();
	printf("%3s", ".");
	reset();
      }
    }
    yellow();
    printf("%3d\n\n", row + 1); // Print right border
    reset();
  }

  // Print bottom border
  
  for (int count = 0; count < 10; count++) {

    if (count > 0 && count < 9) {
      yellow();
      printf("%3d", count);
      reset();
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

// Begin function 'testClosed'

int testClosed(int start[], int finish[])
{
  int counter = 0; // Count the number of moves

  for (int count = 0; count < 8; count++) {

    int startRow, startColumn, finishRow, finishColumn;
    int horizontal[8] = {2, 1, -1, -2, -2, -1, 1, 2}; // Declare array 'horizontal'
    int vertical[8] = {-1, -2, -2, -1, 1, 2, 2, 1}; // Declare array 'vertical'

    finishRow = finish[0] + horizontal[count];
    finishColumn = finish[1] + vertical[count];
    startRow = start[0];
    startColumn = start[1];
    
    if (startRow == finishRow && startColumn == finishColumn) {
      counter++;
    }
  }
  
  /* green(); */

  if (counter == 1) {
    /* puts("          Closed Tour!\n") ; */
    return 1;
    /* reset(); */
  }
  else {
    /* reset(); */
    return 0;
  }
}

// Begin function 'red'

void red(void)
{ 
  printf("\033[0;31m"); 
} // End funtion 'red'

// Begin function 'blue'

void blue(void)
{
  printf("\033[0;34m"); 
} // End function 'blue'

// Begin function 'green'

void green(void)
{
  printf("\033[0;32m");
} // End function 'green'

// Begin function 'yellow'

void yellow(void)
{
  printf("\033[0;33m");  
} // End function 'yellow'

// Begin function 'reset'

void reset(void)
{
  printf("\033[0m");
} // End function 'reset'

