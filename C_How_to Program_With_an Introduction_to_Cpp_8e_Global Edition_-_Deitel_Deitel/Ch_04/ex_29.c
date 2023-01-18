#include <stdio.h>

int main(void)
{
  int x, y, a, b, g, i, j;
  
  if (!(x < 5) && !(y >= 7) == !((x < 5) || (y >= 7))){
    printf("Statement a) true\n");
  }
  else {
    printf("Statement a) false\n");
  }
  
  if (!(a == b) || !(g != 5) ==!((a == b) && (g != 5))) {
    printf("Statement b) true\n");
  }
  else {
    printf("Statement b) false\n");
  }

  if (!((x <= 8) && (y > 4)) == !((x <= 8) || (y > 4))) {
    printf("Statement c) true\n");
  }
  else {
    printf("Statement c) false\n");
  }
  
  if (!((i > 4) || (j <= 6)) == !((i > 4) && (j <= 6))) {
    printf("Statement d) true\n");
  }
  else {
    printf("Statement d) false\n");
  }
}
