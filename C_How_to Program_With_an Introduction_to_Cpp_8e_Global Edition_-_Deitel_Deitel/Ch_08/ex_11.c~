#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(void)
{
  srand(time(NULL));

  char *string, c;
  char *article[] = { "the", "a", "one", "some", "many" };
  char *noun[] = { "boy", "girl", "dog", "town", "car" };
  char *verb[] = { "drove", "ran", "jumped", "walked", "skipped" };
  char *preposition[] = { "to", "from", "over", "under", "on" };

  puts("\n*** Random Sentence Generator ***\n");
  
  for (int i = 0; i < 20; i++) {

    string = &article[rand() % 4][0];
    c = toupper(string[0]);
    string = &string[1];
    
    printf("%s%d%s%c%s %s %s %s%s\n",
	   "Sentence ", i + 1, ": ",
	   c, string, noun[rand() % 4],
	   verb[rand() % 4], preposition[rand() % 4], ".");
  }
  puts("");
}
