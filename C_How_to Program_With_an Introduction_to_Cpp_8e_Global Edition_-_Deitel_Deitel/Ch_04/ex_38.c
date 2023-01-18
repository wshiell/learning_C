#include <stdio.h>

int main(void)
{
  for ( int day = 1; day <= 12; day++) {
    
    printf("%s", "On the ");
  
    switch (day) {
    case 1:
      printf("%s", "First ");
      break;
    case 2:
      printf("%s", "Second ");
      break;
    case 3:
      printf("%s", "Third ");
      break;
    case 4:
      printf("%s", "Fourth ");
      break;
    case 5:
      printf("%s", "Fifth ");
      break;
    case 6:
      printf("%s", "Sixth ");
      break;
    case 7:
      printf("%s", "Seventh ");
      break;
    case 8:
      printf("%s", "Eigth ");
      break;
    case 9:
      printf("%s", "Ninth ");
      break;
    case 10:
      printf("%s", "Tenth ");
      break;
    case 11:
      printf("%s", "Eleventh ");
      break;
    case 12:
      printf("%s", "Twelfth ");
      break;
    }

    printf("%s", "day of Christmas, my true love gave to me,\n");
  
    switch (day) {
    case 12:
      printf("%s", "Twelve drummers drumming\n");
    case 11:
      printf("%s", "Eleven pipers piping\n");
    case 10:
      printf("%s", "Ten Lords a-leaping\n");
    case 9:
      printf("%s", "Nine ladies dancing\n");
    case 8:
      printf("%s", "Eight maids a-milking\n");
    case 7:
      printf("%s", "Seven swans a-swimming\n");
    case 6:
      printf("%s", "Six gees a-laying\n");
    case 5:
      printf("%s", "Five golden rings\n");
    case 4:
      printf("%s", "Four calling birds\n");
    case 3:
      printf("%s", "Three French hens\n");
    case 2:
      printf("%s", "Two turtle doves\n");
    case 1:

      if (day > 1) {
	printf("%s", "and ");
      }
      printf("%s", "A partridge in a pear tree. ");
      break;
    }
    puts("");
    puts("");
  }
}
