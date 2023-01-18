#include <stdio.h>

int mystery(int a, int b);

int main(void)
{
  printf("%s", "Enter two positve integers: ");
  int x;
  int y;
  scanf("%d%d", &x, &y);

  if (y < 0) {
    y = -y;
    printf("The result is %d\n", -mystery(x, y));
  }
  else {
    printf("The result is %d\n", mystery(x, y));    
  }
}

int mystery(int a, int b)
{

  if (1 == b) {
    return a;
  }
  else {
    return a + mystery(a, b - 1);
  }
}
