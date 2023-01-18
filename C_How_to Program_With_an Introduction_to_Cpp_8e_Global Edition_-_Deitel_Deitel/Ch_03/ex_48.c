#include <stdio.h>

int main( void )
{

  int original_number, encrypted_number, digit1, digit2, digit3, digit4, temp;

  puts( "Enter a 4-digit number (-1 to end):" );
  scanf( "%d", &original_number );
  
  while( original_number != -1 ){
    digit1 = original_number / 1000;
    digit2 = ( original_number % 1000 ) / 100;
    digit3 = ( original_number % 100 ) / 10;
    digit4 = original_number % 10;

    printf( "Digits: %d %d %d %d\n\n", digit1, digit2, digit3, digit4 );

    digit1 = ( digit1 + 7 ) % 10;
    digit2 = ( digit2 + 7 ) % 10;
    digit3 = ( digit3 + 7 ) % 10;
    digit4 = ( digit4 + 7 ) % 10;

    temp = digit1;
    digit1 = digit3;
    digit3 = temp;
    temp = digit2;
    digit2 = digit4;
    digit4 = temp;

    encrypted_number = digit1 * 1000 + digit2 * 100 + digit3 * 10 + digit4;
    printf( "Encrypted number: %d\n", encrypted_number );

    puts( "Enter a 4-digit number:" );
    scanf( "%d", &original_number );
  }

  puts( "Enter an encrypted number (-1 to end):" );
  scanf( "%d", &encrypted_number );

  while( encrypted_number != -1 ){
    digit1 = encrypted_number / 1000;
    digit2 = ( encrypted_number % 1000 ) / 100;
    digit3 = ( encrypted_number % 100 ) / 10;
    digit4 = encrypted_number % 10;

    printf( "Digits: %d %d %d %d\n\n", digit1, digit2, digit3, digit4 );

    temp = digit1;
    digit1 = digit3;
    digit3 = temp;
    temp = digit2;
    digit2 = digit4;
    digit4 = temp;

    digit1 = ( digit1 + 3 ) % 10;
    digit2 = ( digit2 + 3 ) % 10;
    digit3 = ( digit3 + 3 ) % 10;
    digit4 = ( digit4 + 3 ) % 10;

    encrypted_number = digit1 * 1000 + digit2 * 100 + digit3 * 10 + digit4;
    printf( "Encrypted number: %d\n", encrypted_number );

    puts( "Enter an encrypted number:" );
    scanf( "%d", &encrypted_number );
  }
}
