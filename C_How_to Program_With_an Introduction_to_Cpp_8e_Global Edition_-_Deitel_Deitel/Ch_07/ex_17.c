#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 70

void randomise(int *harePosition, int *tortoisePosition);
void printTrack(int harePosition, int tortoisePosition, char *track[SIZE]);

int main(void)
{
  srand(time(NULL));

  int harePosition = 0, tortoisePosition = 0;
  int hareMove, tortoiseMove;
  char *track[SIZE];

  puts("BANG !!!!\nAND THEY'RE OFF !!!!!\n");

  while (harePosition < SIZE - 1 && tortoisePosition < SIZE - 1) {

    randomise(&harePosition, &tortoisePosition);

    if (harePosition <= 0) {
      harePosition = 0;
    }

    if (tortoisePosition <= 0) {
      tortoisePosition = 0;
    }

    if (harePosition >= SIZE - 1){
      harePosition = SIZE - 1;
    }

    if (tortoisePosition >= SIZE - 1) {
      tortoisePosition = SIZE - 1;
    }
    printTrack(harePosition, tortoisePosition, track);
  }

  if (tortoisePosition > harePosition) {
    printf("TORTOISE WINS!!! YAY!!!\n");
  }
  else {

    if (tortoisePosition < harePosition) {
      printf("Hare wins. Yuch.\n");
    }
    else {
      printf("It's a tie.");
    }
  }
}

void randomise(int *harePosition, int *tortoisePosition)
{
  int hareMove = 1 + rand() % 10;
  int tortoiseMove = 1 + rand() % 10;

  if (tortoiseMove >= 1 && tortoiseMove <= 5) {
    *tortoisePosition += 3;
  }

  if (tortoiseMove >=6 && tortoiseMove <=7) {
    *tortoisePosition -= 6;
  }

  if (tortoiseMove >= 8 && tortoiseMove <= 10) {
    *tortoisePosition++;
  }

  if (hareMove >= 1 && hareMove <= 2) {
    *harePosition;
  }

  if (hareMove >= 3 && hareMove <= 4) {
    *harePosition += 9;
  }

  if (hareMove == 5) {
    *harePosition -= 12;
  }

  if (hareMove >= 6 && hareMove <= 8) {
    *harePosition++;
  }

  if (hareMove >= 9 && hareMove <= 10) {
    *harePosition += 2;
  }
}

void printTrack(int harePosition, int tortoisePosition, char *track[SIZE])
{
  for (size_t i = 0; i < SIZE; i++) {
    track[i] = " ";
  }
  
  if (harePosition != tortoisePosition) {
    track[harePosition] = "H";
    track[tortoisePosition] = "T";
  }
  else {
    track[harePosition] = "OUCH!!!";
  }
 
  for (size_t i = 0; i < SIZE; i++) {
    printf("%s", track[i]);
  }
  puts("");
}
