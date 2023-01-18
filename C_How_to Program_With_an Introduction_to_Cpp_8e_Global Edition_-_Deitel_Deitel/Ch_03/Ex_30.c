#include <stdio.h>

int main( void )
{
  //Part A
  int x = 9;
  int y = 11;
  if( x < 10 )
    if( y > 10 )
      puts( "*****" );
    else
      puts( "#####" );
  puts( "&&&&&" );

  x = 11;
  y = 9;
  if( x < 10 )
    if( y > 10 )
      puts( "*****" );
    else
      puts( "#####" );
  puts( "&&&&&" );

  //Part B
  x = 9;
  y = 11;
  if( x < 10 ) {
    if( y > 10 )
      puts( "*****" );
  }
  else {
    puts( "#####" );
    puts( "&&&&&" );
  }

  x = 11;
  y = 9;
  if( x < 10 ) {
    if( y > 10 )
      puts( "*****" );
  }
  else {
    puts( "#####" );
    puts( "&&&&&" );
  }

}
