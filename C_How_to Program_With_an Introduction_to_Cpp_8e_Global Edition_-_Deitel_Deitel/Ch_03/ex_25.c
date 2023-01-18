#include <stdio.h>

int main( void )
{

  int number = 1, plusThree, plusSix, plusNine, counter = 0;

  puts( "A\tA + 3\tA + 6\tA + 9" );
  
  while( counter < 5 ) {
    plusThree = number + 3;
    plusSix = plusThree + 3;
    plusNine = plusSix + 3;
    printf( "%d\t%d\t%d\t%d\n", number, plusThree, plusSix, plusNine );
    counter++;
    number++;

  }
}
