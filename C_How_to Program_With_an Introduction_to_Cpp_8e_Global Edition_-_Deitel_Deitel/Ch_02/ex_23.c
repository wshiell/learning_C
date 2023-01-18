#include <stdio.h>

int main ( void )
{

  int a, b, c;

  puts( "Enter three integers: " );
  scanf( "%d%d%d", &a, &b, &c );

  if ( a == b ) {
    if ( b == c ) {
      printf( "All numbers are the same size ( %d = %d = %d ).\n", a, b, c );
    }
  }
  if ( a == b ) {
    if ( c > b ) {
      printf( "Smallest numbers are: %d, %d\n", a, b );
      printf( "Largest numbers are: %d\n", c );
    }
    if ( c < b ) {
      printf( "Smallest numbers are: %d\n", c );
      printf( "Largest numbers are: %d, %d\n", a, b );
      a = b;
    }
  }
  if ( a == c ) {
    if ( b > c ) {
      printf( "Smallest numbers are: %d, %d\n", a, c );
      printf( "Largest numbers are: %d\n", b );
    }
    if ( b < c ) {
      printf( "Smallest numbers are: %d\n", b );
      printf( "Largest numbers are: %d, %d\n", a, c );
    }
    a = c;
  }
  if ( b == c ) {
    if ( a > c ) {
      printf( "Smallest numbers are: %d, %d\n", b, c );
      printf( "Largest numbers are: %d\n", a );
    }
    if ( a < c ) {
      printf( "Smallest numbers are: %d\n", a );
      printf( "Largest numbers are: %d, %d\n", b, c );
    }
    b = c;
  }
  if ( a > b ) {
    if ( a > c ) {
      printf( "Largest number is: %d\n", a );
    }
    if ( b < c ) {
      printf( "Smallest number is: %d\n", b );
    }
    if ( b > c ) {
      printf( "Smallest number is: %d\n", c );
    }
    if ( b == c ) {
      puts( "" );
    }
  }
  if ( c > b ) {
    if ( c > a ) {
      printf( "Largest number is: %d\n", c );
    }
    if ( b < a ) {
      printf( "Smallest number is: %d\n", b );
    }
    if ( b > a ) {
      printf( "Smallest number is: %d\n", a );
    }
    if ( b == a ) {
      puts( "" );
    }
  }
  if ( b > a ) {
    if ( b > c ) {
      printf( "Largest number is: %d\n", b );
    }
    if ( a < c ) {
      printf( "Smallest number is: %d\n", a );
    }
    if ( a > c ) {
      printf( "Smallest number is: %d\n", c );
    }
    if ( a == c ) {
      puts( "" );
    }
  }
}
