//  ***************************************************************************
//  *
//  *    bar.c -- 
//  *    Author: Wade Shiell
//  *    Sat Jan 11 14:37:56 2020
//  *
//  ***************************************************************************

#include <stdio.h>

void foo(int bar);
void useGlobal();
enum status {WIN, LOSE, CONTINUE};
int x = 1;

int main(void)
{
  int x = 2;
  useGlobal();
}


void foo(int bar)
{

}

void useGlobal()
{
  printf("x = %d\n", x);
}
