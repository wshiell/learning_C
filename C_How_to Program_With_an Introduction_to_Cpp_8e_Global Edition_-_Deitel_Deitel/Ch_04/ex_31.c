#include <stdio.h>

int main()
{
  int number1;
  int number2;

  for(int count1 = 1; count1 <= 9; count1++) {

    if (count1 <= 5) {
      number1 = 2 * (count1 - 1) + 1;
      number2 = -count1;
    }
    else {
      number1 = 2 * (9 - count1) + 1;
      number2 = (count1 - 10);
    }
    
    for (int count2 = 1; count2 < 6 + number2; count2++) {
      printf( "%s", " ");
    }
    
    for (int count2 = 1; count2 <= number1; count2++) {
      printf("%s", "*");
    }
    
    puts("");
  }
}
