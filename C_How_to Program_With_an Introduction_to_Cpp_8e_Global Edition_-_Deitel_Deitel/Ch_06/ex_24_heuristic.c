#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MOVES 52 // Number of maxiumum moves
#define TRIALS 1000 // Set the number of trial runs

// Function which runs multiple tour iterations

int tour(int SIZE);

// Function which moves knight for each value of 'move'

int moveKnight(int move, int position[], int board[][8]);

// Function prints the board after moves have been made

void printBoard(int board[][8], int position[]);

// Function generates a random array of eight unique numbers

void generateRandom(int randomNumber[]);

// Graph the data

void graphData(double data[]);

// Begin function 'main'

int main(void)
{
  srand(time(NULL));

  double average = 0; // Indicates average number of tour iterations
  double oldAverage = 0; // Average from previous iteration run
  int total = 0; // Running counter total for each tour iteration
  int counter = 1; // Indicates the number of tour iterations
  int max = 0; // Indicates the maxiumum number of moves made in a given tour
  double data[MOVES] = {0};

  // Print header for table
  
  printf("\n%20s%30s%20s\n\n", "Move #", "Average # of tours", "Av - old Av.");

  // Print result for moves = 1
  
  printf("%20d%30f%20s\n", 1, (float) 1, "n/a");
  data[0] = (float) 1;

  // Run a series of tours for each value of the number of moves, up to max number
  // and determine the average value of tours for each move value
  
  for (int SIZE = 2; SIZE <= MOVES; SIZE++) { // SIZE: Upper value for given tour
    
    for (int counter2 = 0; counter2 < TRIALS; counter2++) {
  
      while (max != SIZE) {
	max = tour(SIZE);

	if (max == SIZE) {
	  break;
	}
	else {
	  counter++;
	}
      }
      // Print number of iterations of tour taken to successfully complete a tour

      /* printf("\nNumber of tour iterations: %d\n", counter); */

      total += counter; // Add counter value to total
      counter = 1; // Reset counter to 1
      max = 0; // Reset max to zero
    }

    average = (float) total / TRIALS; // Calculate average
    data[SIZE - 1] = average;    
    // Print each line of results
    
    printf("%20d%30f%20.2f\n", SIZE, average, average - oldAverage);
    oldAverage = average;
    average = 0; // Reset average to zero
    total = 0; // Reset total to zero
  }

  // Print data summary
  
  printf("\nNumber of iterations per move length: %d\n", TRIALS);
  printf("Number of maximum moves made: %d\n", MOVES);

  // Call 'graphData' function to display a graph of the data

  graphData(data);
  
} // End function 'main'

// Begin function 'tour'

int tour(int SIZE)
{
  int max = 0; // Reset maximum number of moves at the start of each tour
  int valid = 0; // Indicates whether the move made was valid
  int board[8][8] = {0}; // Declare and initialise array 'board'
  int position[2]; // Declare array describing knight's position
  
  position[0] = 4; // Initial row position of knight
  position[1] = 4; // Initial column position of knight
  board[position[0]][position[1]] = 1; // Declare starting position of knight

  // Run program over multiple iterations until a successful tour is completed

    for (int move = 1; move < SIZE; move++) { // Move the knight

      valid = moveKnight(move, position, board); // Call function 'moveKnight
      max = board[position[0]][position[1]]; // Max is largest value in array 'board'

      // If tour unsuccessful, print move at which tour terminates
      
      if (max < SIZE && move == SIZE - 1) {
	/* printf("\nTour terminated at move #%d\n", max); */
	break;
      }

      // If tour successful, print 'Successful Tour!'
      
      if (max == SIZE) {
	/* puts("\nSuccessful Tour!"); */
      }
    }
    /* printBoard(board, position); // Call function 'printBoard' */

    return max;
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
      testArray[count] = 9;
    }
    else {

      // Ensure the knight does not move back to a previously occupied square
    
      if (board[currentRow][currentColumn] != 0) {
        testArray[count] = 10;
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
      
    if (testArray[count] != 9) {
      tempRow += horizontal[randomNumber[count]];
      tempColumn += vertical[randomNumber[count]];
      accessibility[tempRow][tempColumn]--;
    }
  }
  
  printf("  After move %d\n", move);
  for (int count = 0; count < 8; count++) {

    for (int count2 = 0; count2 < 8; count2++) {
      printf("%3d", accessibility[count][count2]);
    }
    puts("");
  }
  puts("");

  // Determine the smallest accessibility number using the valid moves available,
  // and set the move number to to corresponding move type
  
  for (int count = 0; count < 8; count++) {

    if (testArray[count] < min && testArray[count] != 0) {
      min = testArray[count];
      moveNumber = randomNumber[count];
    }
  }

  // Change knight's position and board values after moving knight

  if (min != 9) {
    position[0] += horizontal[moveNumber];
    position[1] += vertical[moveNumber];
    board[position[0]][position[1]] = move + 1;
  }
} //End function 'moveKnight'

// Begin function 'graphData'

void graphData(double data[])
{
  int counter = 0;
  int DIMENSION = (int) data[MOVES - 1] + 1; // Determines height of array 'graph'
  double graph[DIMENSION][MOVES]; // Declare array 'graph'

  // Initialise array 'graph' to zero
  
  for (int row = 0; row < DIMENSION; row++) {

    for (int column = 0; column < MOVES; column++) {

      graph[row][column] = 0;
    }
    counter++; // Increment counter
  }
  puts("");

  // Add elements from array 'data' to array 'graph'

  for (int row = 0; row < DIMENSION; row++) {

    for (int column = 0; column < MOVES; column++) {

      if (data[column] > row && data[column] <= row + 1) {
	graph[(DIMENSION - 1) - row][column] = 1;
      }
    }
  }
  
  // Print array 'graph'

  // Print y-axis label

  printf("%10s\n", "Average\nnumber\nof\nattempts");
  
  for (int row = 0; row < DIMENSION; row++) {

    printf("%10d%2s", DIMENSION - row, "|"); // Print left border
      
    for (int column = 0; column < MOVES; column++) {

      if (graph[row][column] == 1) {
        printf("%2s", "*");
      }
      else {
	printf("%2s", " ");
      }
    }
    puts("");
  }

  // Print bottom border

  printf("%10s", " ");
  for (int count = 0; count < MOVES + 1; count++) {
    printf("%2s", "-");
  }
  
  printf("\n%10s", " ");

  for (int count = 0; count < MOVES + 1; count++) {
    if ((count + 1) % 6 == 0) {
      printf("%2d", count);
    }
    else {
      printf("%2s", " ");
    }
  }
  printf("\n%70s\n", "Number of squares moved");
}

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
