#include <stdio.h>

int main()
{
  int number1;
  int number2;
  int number;

  puts("Enter an odd integer between 1 - 19 (-1 to quit):");
  scanf("%d", &number);

  puts("");

  while (number != -1) {
  
    for(int count1 = 1; count1 <= number; count1++) {

      if (count1 <= number / 2 + 1) {
	number1 = 2 * (count1 - 1) + 1;
	number2 = -count1;
      }
      else {
	number1 = 2 * (number - count1) + 1;
	number2 = (count1 - (number + 1));
      }
    
      for (int count2 = 1; count2 < ((number + 4) / 2) + number2; count2++) {
	printf( "%s", " ");
      }
    
      for (int count2 = 1; count2 <= number1; count2++) {
	printf("%s", "*");
      }
    
      puts("");
    }
    puts("Enter an odd integer between 1 - 19 (-1 to quit):");
    scanf("%d", &number);
  }
}
