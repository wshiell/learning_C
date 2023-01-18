#include <stdio.h>
#include <ctype.h>

int main(void)
{
  int i = 0;
  char s[100];
  char *line;

  puts("Enter a line of text:\n");
  fgets(line, 100, stdin);

  while (line[i] != '\0') {

    if (i % 2 == 0) {
      line[i] = toupper(line[i]);
    }
    else {
      line[i] = tolower(line[i]);
    }
    
    s[i] = line[i];
    i++;
  }

  printf("%s\n\n", "The line of text in alternating upper and lower case is:");
  puts(s);
}
