#include <stdio.h>

int main ( void )
{

  int b, c;
  int i = 1;

  puts( "What's my favourite number?" );
  scanf( "%d", &c );
  b = c;
  
  while( i < b ) {
    printf( "%d, A! A! A!\n", i++ );
  }

  printf( "%d!!!!!! *thunder noise*\n", c );
  puts( "Everybody, one more time!!!" );
  i = 1;
  
  while( i < c ) {
    printf( "%d, A! A! A!\n", ++i );
  }

  puts( "Wait, where did 1 go??");
}
