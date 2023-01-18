#include <stdio.h>
#include <math.h>

int main(void)
{
  printf("%-15s%-15s%-15s%-15s", "Decimal", "Binary", "Octal", "Hexadecimal");
  puts("");

  for (int counter = 1; counter <= 256; counter++) {
    int binary = 0;
    int temp = counter;

    for (int number = 8; number >= 0; number--) {
      binary += (temp / (int) pow(2, number)) * ((int) pow(10, number));
      temp = (temp % (int) pow(2, number));
    }
    
    printf("%-15d%-15d%-15o%-15X", counter, binary, counter, counter);
    puts("");
  }
}

