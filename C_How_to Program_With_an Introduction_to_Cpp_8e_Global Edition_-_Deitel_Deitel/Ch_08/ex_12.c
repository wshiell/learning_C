#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SIZE 5

int main(void)
{
  srand(time(NULL));

  puts("\n*** Random Limerick Generator ***");
  
  char *firstLine[] = { "There once was a bug who called ", "Two frogs ate a bowlful of ",
                        "A girl called Jemimah was ", "One day a boy ask of his ",
                        "When nothing is ever so " };
  char *firstWord[] = { "pleasing,", "choosing,", "tensing,", "cleansing,", "asking," };
  char *secondLine[] = { "Who couldn't eat munckins with ", "Where all my good gweilo are ",
                         "And no-one was ever too ", "Or three times the farthing went ",
                         "But lonesome the cuckoo did " };
  char *secondWord[] = { "owling.", "teasing.", "shoestring.", "grousing.", "ending." };
  char *thirdLine[] = { "You never could ", "But rarely did ", "And seldom were ",
                        "For always we ", "Lo! Look there " };
  char *thirdWord[] = { "unction.",  "function.", " trunction.", "truncheon.", "sussing." };
  char *fourthLine[] = { "And three ways ", "Where ne'er the ", "Or I couldnt ",
                         "Fritz, pass me ", "Now didn't he " };
  char *fourthWord[] = { "brush them.", "touch them.", "luncheon.", "wunchion.", "lopan." };
  char *fifthLine[] = { "For all were not there at the ", "But merrily did we all ",
                        "Or if we could see them then ", "Touch all the sweet toilets now ",
                        "Up, up on the high horse he " };
  char *fifthWord[] = { "browing.", "awning.", "feeding.", "dueling.", "tenting." };
  
  for (int limerick = 0; limerick < SIZE; limerick++) {
  
    printf("\n%s%s\n%s%s\n%s%s\n%s%s\n%s%s\n",
	   firstLine[rand() % SIZE], firstWord[rand() % SIZE],
	   secondLine[rand() % SIZE], secondWord[rand() % SIZE],
	   thirdLine[rand() % SIZE], thirdWord[rand() % SIZE],
	   fourthLine[rand() % SIZE], fourthWord[rand() % SIZE],
	   fifthLine[rand() % SIZE], fifthWord[rand() % SIZE]);
  }
  puts("");
}
