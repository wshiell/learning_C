#include <stdio.h>
#include <math.h>

#define GRID 46
#define LIMIT 100

enum pen {UP, DOWN};

void turtle(const int instructions[], int count, int x, int y);
int turnLeft(int orientation);
int turnRight(int orientation);
int move(int floor[][GRID], int position[], int distance, int orientation,
	 int penStatus);
void printArray(const int floor[][GRID]);
	       
int main(void)
{
  // Declare and initialise array 'instructions'

  int instructions[LIMIT] = {0};

  // Declare variables

  int command;
  int count = 0;
  int x, y;

  // Print instructions for user

  puts("\n*** Welcome to the Turtle Graphics program ***\n");
  puts("Please select from the following list of commands when entering values:\n");
  puts("  1    - Pen Up");
  puts("  2    - Pen Down");
  puts("  3    - Turn Left");
  puts("  4    - Turn Right");
  puts("  5, X - Move a distance of 'X' units (ensure 5 and X are seperated by a space)");
  puts("  6    - Print Array");
  puts("  9    - End of Data");
  
  // Display initial user prompts

  puts("\nSet initial position (x, y):");
  scanf("%d%d", &x, &y);
  
  puts("\n*** Enter instructions for the TURTLE (9 to quit) ***");
  printf("\n   (Note: number of commands must be less than %d)\n\n", LIMIT);
  printf("Command #%d: ", count + 1);
  scanf("%d", &command);

  // Input command values
  
  while (command != 9) {
    instructions[count] = command;
    count++;

    printf("Command #%d: ", count + 1);    
    scanf("%d", &command);
  }

  instructions[count] = command;

  // Copy commands to new array 'temp'

  int temp[count];

  for (int counter = 0; counter < count; counter++) {
    temp[counter] = 0;
  }

  for (int counter = 0; counter < count; counter++) {
    temp[counter] = instructions[counter];
  }

  // Change size of array 'instructions' to match array 'temp', and copy values
  
  instructions[count];

  for (int counter = 0; counter < count; counter++) {
    instructions[counter] = temp[counter];
  }

  puts("");
  
  // Call function 'turtle'
  
  turtle(instructions, count, x, y);
}

void turtle(const int instructions[], int count, int x, int y)
{
  // Delcare variable 'direction' (the direction you want the turtle to move)

  int direction;
  
  // Declare variable 'orientation' (the direction the turtle is pointing)

  int orientation = 0;  

  // Declare variable 'distance' (the distance the turtle will move)

  int distance;
  
  // Declare and initialise variable of type 'pen' (describes pen orientation)
  
  enum pen penStatus;

  penStatus = UP;

  // Declare and initialise array 'position' 
  
  int position[2] = {x, y};

  // Declare and initialise array 'floor'

  int floor [GRID][GRID] = {0};

  // Loop through each command in array 'instructions'
  
  for (int counter = 0; counter < count; counter++) {

    switch (instructions[counter]) {
      
    case 1:
      penStatus = UP;
      break;
    case 2:
      penStatus = DOWN;
      floor[position[0]][position[1]] = 1;
      break;
    case 3:
      orientation = turnLeft(orientation);
      break;
    case 4:
      orientation = turnRight(orientation);
      break;
    case 5:
      counter++;
      distance = instructions[counter];
      orientation = move(floor, position, distance, orientation, penStatus);
      break;
    case 6:
      printArray(floor);
      break;
    case 7:
      break;
    }
  }
}

// Turn the turtle left

int turnLeft(int orientation)
{
  int direction = -1;

  orientation += direction;

  if (orientation >= 0) {
    orientation = (int) orientation % 4;
  }
  else {
    orientation = (4 - (int) fabs(orientation)) % 4;
  }
  
  return orientation;
}

// Turn the turtle right

int turnRight(int orientation)
{
  int direction = 1;

  orientation += direction;

  if (orientation >= 0) {
    orientation = (int) orientation % 4;
  }
  else {
    orientation = (4 - (int) fabs(orientation)) % 4;
  }
  
  return orientation;  
}  

// Move the turtle's position

int move(int floor[][GRID], int position[], int distance, int orientation,
	 int penStatus)
{
  // Declare variables for turtle's x and y positions

  int position_X = position[0];
  int position_Y = position[1];

  puts("");
  
  // Change value of array 'floor' according to pen orientation and distance moved
  
  for (int count = 0; count < distance; count++) {

    switch (orientation) {

    case 0:
      position_Y++;
      break;
    case 1:
      position_X++;
      break;
    case 2:
      position_Y--;
      break;
    case 3:
      position_X--;
      break;
    }
    
    if (penStatus == UP) {
      continue;
    }
    else {
      floor[position_X][position_Y] = 1;
    }
  }

  position[0] = position_X;
  position[1] = position_Y;

  return orientation;
}

// Print array 'floor'

void printArray(const int floor[][GRID])
{
  for (int counter = 0; counter < GRID + 2; counter++)  {
    printf("%s ", "X");
  }

  puts("");
  
  for (int row = 0; row < GRID; row++) {

    printf("%s ", "X");

    for (int column = 0; column < GRID; column++) {
      if (floor[row][column] == 1) {
      printf("%s ", "*");
      }
      else {
      	printf("%s ", " ");
      }
    }
    printf("%s", "X");
    puts("");
  }

  for (int counter = 0; counter < GRID + 2; counter++)  {
    printf("%s ", "X");
  }

  puts("");
}
