#include <stdio.h>

int main(void)
{
  int i = 0, j = 0, k = 1;

  goto start;
  
 star: printf("%s", "*"); goto start;
 newline: printf("%s", "\n"); goto start;
 space: printf("%s", " "); goto start;
  
 start:

  if (i < 29) {
    i++;

    if ((i % 6) != 0) {
      j++;

      if ((j % 5) == 0 || ((j - 1) % 5) == 0 ||
	  (k == 1) || k == 5) {
	goto star;
      }
      else {
	goto space;
      }
    }
    else {
      k++;
      goto newline;
    }
    goto start;
  }
  puts("");
}
