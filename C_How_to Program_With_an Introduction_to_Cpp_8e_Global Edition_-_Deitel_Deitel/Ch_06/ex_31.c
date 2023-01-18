// ****************************************
//
// Chapter 6, ex_31.c
//
// ****************************************

#include <stdio.h>

int stringLength(char string[]);
int testPalindrome(char string[], int length, int first);

// Functions to control text colour

void red(void); // Red
void blue(void); // Blue
void green(void); // Green
void beige(void); // Beige
void white(void); //White
void reset(void); // Resets colour to default

int main(void)
{
  char string[20];
  int candidate;
  int length;
  int first = 0;

  blue();
  puts("\nEnter a string to test whether or not it is a palindrome (q to quit):");
  reset();

  scanf("%s", string);
  
  while (string[0] != 'q') {
  
    length = stringLength(string);
    candidate = testPalindrome(string, length, first);

    if (candidate == 1) {

      green();
      printf("\n%s *is* a palindrome\n\n", string);
      reset();
    }
    else {
      red();
      printf("\n%s is *not* a palindrome\n\n", string);
      reset();
    }
    puts("Enter a string to test whether or not it is a palindrome: (-1 to quit)");
    scanf("%s", string);
  }
}

int stringLength(char string[])
{
  int tally = 0;
  
  while (string[tally] != '\0') {

    tally++;
  }

  return tally;
}

int testPalindrome(char string[], int length, int first)
{
  if (first >= length) {
    return 1;
  }
  else {

    if (string[first] == string[length - 1]) {
      testPalindrome(string, length - 1, first + 1);
    }
    else {
      return 0;
    }
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
