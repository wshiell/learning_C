// ****************************************
//
// Chapter 6, ex_27b
//
// ****************************************

#include <stdio.h>
#include <math.h>

#define SIZE 8
#define QUEENS 8

// Function to initialise arrays

void initialise(int board[][SIZE], int Q[][2]);

// Function which adds a queen to the board

void addQueen(int board[][SIZE], int Q[][2], int shift, int count);

// Function which prints the board

void printBoard(int board[][SIZE], int Q[][2]);

// Functions to control text colour

void red(void); // Red
void blue(void); // Blue
void green(void); // Green
void beige(void); // Beige
void white(void); //White
void reset(void); // Resets colour to default

// Begin function 'main'

int main(void)
{
  green();
  printf("\n%28s\n", "**Eight Queens Puzzler**"); // Title display for program
  printf("\n%28s\n\n", "(Exhaustive Brute Force Attempt)");
  reset();
  
  int attempts = 0; // Number of attempts made to acheive a successful solution
  int shift = 0; // Number of squares the first queen is shifted if the puzzle solution fails
  
  // Until a successful solution is achieved, loop the program, moving the starting square one
  // place to the right each time
  
  while (attempts != -1) {

    attempts++; // Increment 'attempts'

    int fail = 0; // Variable 'fail' remains 0 until the puzzle is solved, and is then set to 1
    int board[SIZE][SIZE]; // Declare  array 'board'
    int Q[SIZE][2]; // Declare  array 'queen' to hold Qs positions

    initialise(board, Q);
    
    // Add queens to the board one at a time (total of 'QUEENS' queens)
    
    for (int count = 0; count < QUEENS; count++) {

      addQueen(board, Q, shift, count); // Attempt to add queen # count to the board

      // Go through the list of previous queen positions. If the last position a queen
      // was placed is in the list, set variable 'fail' equal to one, which will cause
      // the while loop to execute again
      
      for (int counter = 0; counter < count; counter++) {

	// Compare the last position to every previous position

	if (Q[counter][0] == -1 && Q[counter][1] == -1){

	  fail = 1;
	}
	else {
	  ; // If the position is new, continue without incrementing 'fail'
	}
      }

      // If the most recent queen was moved to a unique position, and the most recent
      // queen was also the eighth queen, set 'attempts' equal to -1, which will cause the
      // program to fall out of the while loop and terminate
      
      if (fail == 0 && count == QUEENS - 1) {

        printf("\n\t(Attempts: %d)\n", (shift + 1) * attempts);
	attempts = -1; // Set attempts equal to -1
		
	printBoard(board, Q); // Print board	  
      }      

      // If the most recent queen was moved to a unique position and the most recen queen
      // was *not* the eighth queen, continue with the next iteration of the while loop
      
      if (fail == 0) {
	;
      }
      else {
	break;
      }
    }
    shift++;
  }
} // End function 'main'

// Begin function 'initialise'

void initialise(int board[][SIZE], int Q[][2])
{
  // Initialise array 'board' to -1
    
  for (int row = 0; row < SIZE; row++) {

    for (int column = 0; column < SIZE; column++) {

      board[row][column] = -1;
    }
  }

  // Initialise array 'Q' to -1

  for (int row = 0; row < SIZE; row++) {

    for (int column = 0; column < 2; column++) {

      Q[row][column] = -1;
    }
  }
} // End function 'initialise'

// Begin function 'addQueen'

void addQueen(int board[][SIZE], int Q[][2], int shift, int count)
{
  int Q0, Q1; // Declare variables to track the queens position
 
  // Set trial position of queen # count
  if (count == 0) {
    count = shift;
  }
  Q0 = count / SIZE;
  Q1 = count % SIZE;
  
  // Place the queen at position (Q0, Q1)

  if (board[Q0][Q1] == -1) {
	  
    for (int row = 0; row < SIZE; row++) {

      for (int column = 0; column < SIZE; column++) {

	if (row == Q0 || column == Q1 || (fabs(row - Q0) == fabs(column - Q1))) {
	  board[row][column] = 0; // Set board position to 0 if attacked by queen
	}
      }
    }
    Q[Q0][0] = Q0; // Set row position to indicate presence of queen
    Q[Q0][1] = Q1; // Set column position to indicate presence of queen

    board[Q0][Q1] = 29; // Set value of position on 'board' to 29
  }
  else {

    if (Q0 == 7 && Q1 == 7) {

      for (int count = 0; count < SIZE; count++) {
	Q[count][0] = -1;
	Q[count][1] = -1;

      }
    }
    else {
      addQueen(board, Q, shift, count + 1);
    }
  }
} // End function 'addQueen'

// Begin function 'printBoard'

void printBoard(int board[][SIZE], int Q[][2])
{
  puts("");

  // Print top number row
  
  for (int count = 0; count < SIZE + 2; count++) {

    if (count != 0 && count != SIZE + 1) {
      beige();
      printf("%3d", count);
      reset();
    }
    else {
      printf("%3s", " ");
    }
  }
  white();
  printf("\t\tPosition #");
  reset();
  puts("\n");

  // Print body of the board
  
  for (int row = 0; row < SIZE * 2; row++) {

    if (row % 2 == 0) {
      beige();
      printf("%3d", (row / 2) + 1); // Print left number column
      reset();
    }
    else {
      printf("%3s", " ");
    }
    
    for (int column = 0; column < SIZE; column++) {

      int temp = (int) row / 2;
      
      if (row % 2 == 0) {
      
	if (board[row / 2][column] != 29) {
	  blue();
	  printf("%3s", "."); // If square is empty, print '.'
	  reset();
	}
	else {
	  red();
	  printf("%3d", temp + 1); // If square contains a queen, print queen number
	  reset();
	}
      }
      else {
	printf("%3s", " ");
      }
    }
    if (row % 2 == 0) {
      beige();
      printf("%3d", (row / 2) + 1); // Print right number column
      reset();
    }
    else {
      printf("%3s", " ");
    }

    if (row < SIZE) {
      white();
      printf("\t\tQueen #%d: (%d, %d)",
	     row + 1, Q[row][0] + 1, Q[row][1] + 1); // Print Q's position
      reset();
    }
    puts("");
  }

  // Print bottom number row
  
  for (int count = 0; count < SIZE + 2; count++) {

    if (count != 0 && count != SIZE + 1) {
      beige();
      printf("%3d", count);
      reset();
      
    }
    else {
      printf("%3s", " ");
    }
  }
  puts("\n");
} // End function 'printBoard'

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

// Begin function 'beige'

void beige(void)
{
  printf("\033[0;36m");  
} // End function 'beige'

// Begin function 'white'

void white(void)
{
  printf("\033[0;37m");
} // End function 'white'

// Begin function 'reset'

void reset(void)
{
  printf("\033[0m");
} // End function 'reset'
