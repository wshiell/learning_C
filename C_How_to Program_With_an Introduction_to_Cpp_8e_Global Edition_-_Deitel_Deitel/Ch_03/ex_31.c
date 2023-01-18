#include <stdio.h>

int main( void )
{

//Part A
  
  int y = 8;
  int x = 5;
  if( y == 8 ) {
    if( x == 5 ) {
      puts( "@@@@@" );
    }
  }
  else {
    puts( "#####" );
  }
  puts( "$$$$$" );
  puts( "&&&&&" );
  puts( "" );
  
//Part B
  y = 8;
  x = 5;
  if( y == 8 ) {
    if( x == 5 ) {
      puts( "@@@@@" );
    }
    else {
      puts( "#####" );
      puts( "$$$$$" );
      puts( "&&&&&" );
    }
  }
  puts( "" );
  
//Part C
  y = 8;
  x = 5;
  if( y == 8 ) {
    if( x == 5 ) {
      puts( "@@@@@" );
    }
    else {
        puts( "#####" );
        puts( "$$$$$" );
    }
  }
  puts( "&&&&&" );
  puts( "" );
  
//Part D
  y = 7;
  x = 5;
  if( y == 8 ) {
    if( x == 5 ) {
      puts( "@@@@@" );
    }
  }
  else {
    puts( "#####" );
    puts( "$$$$$" );
    puts( "&&&&&" );
  }
  puts( "" );
}
