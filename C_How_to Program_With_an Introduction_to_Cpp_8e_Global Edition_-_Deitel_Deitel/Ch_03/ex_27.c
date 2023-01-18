#include <stdio.h>

int main( void )
{

  unsigned int passes = 0;
  unsigned int failures = 0;
  unsigned int student = 1;
  int result, i = 0;

  while ( student <= 10 ) {

    printf( "%s", "Enter result ( 1 = pass, 2 = fail )" );
    scanf( "%d", &result );

    while ( i != 1 ) {
      if( result != 1 ) {
        if( result != 2 ) {
          puts( "Invalid entry." );
	  printf( "%s", "Enter result ( 1 = pass, 2 = fail )" );
	  scanf( "%d", &result );
        }
      }
      if( result == 1 ) {
	i++;
      }
      else {
	if( result == 2 ) {
	  i++;
	}
      }
    }
    if ( result == 1 ) {
      passes = passes + 1;
    }
    else {
      failures = failures + 1;
    }

    student = student + 1;

  }

  printf( "Passed %u\n", passes );
  printf( "Failures %u\n" , failures );

  if ( passes > 8 ) {
    puts( "Bonus to instructor!" );
  }
}
