#include <stdio.h>

int main( void )
{

  int num;
  int i = 2;

  puts( "Enter a number to test whether or not it is prime:" );
  puts( "(Enter -1 to quit)" );
  scanf( "%d", &num );

  while( num != -1 ) {
    if( num == 2 ) {
      printf( "%d is prime\n", num );
    }
    else {
      while( i < num ) {
        if( num % i != 0 ) {
  	  ++i;
          if( i == num ) {
            printf( "%d is prime\n", num );
          }
        }
	else {
	  printf( "%d is not prime\n", num );
	  i = num;
	}
      }
    }
    
    i = 2;

    puts( "Enter a number to test whether or not it is prime:" );
    puts( "(Enter -1 to quit)" );
    scanf( "%d", &num );
  }
}
