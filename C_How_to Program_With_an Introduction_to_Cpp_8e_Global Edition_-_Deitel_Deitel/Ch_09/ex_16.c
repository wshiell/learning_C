#include <stdio.h>

int main(void)
{
  printf("%s\n%c%s\n", "\? as a character constant: ", '?',
	 " has printed successfully.");
  printf("%s\n%c%s\n", "\? as a character constant escape sequence: : ", '\?',
	 " has printed successfully.");  
}
