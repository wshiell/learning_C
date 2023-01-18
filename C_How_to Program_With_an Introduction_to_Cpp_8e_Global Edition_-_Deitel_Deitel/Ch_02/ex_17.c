#include <stdio.h>

// start function main
int main ( void )
{

  int u; // initial velocity
  int v; // final velocity
  int a; // acceleration
  int t; // time
  float s; // distance

  puts( "Enter initial velocity: " );
  scanf( "%d", &u );

  puts( "Enter acceleration: " );
  scanf( "%d", &a );

  puts( "Enter elapsed time: " );
  scanf( "%d", &t );

  v = u + a * t; // formula for final velocity
  s = u * t + ( ( float ) 1 / 2 ) * a * t * t;

  printf( "Final velocity: %d\n", v ); // prints value for final velocity
  printf( "Displacement: %.2f\n", s ); // prints value for displacement

} // end function main
