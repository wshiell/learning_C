#include <stdio.h>

int main(void)
{
  int GPA[10] = {46, 57, 34, 86, 87, 76, 97, 65, 45, 86};

  printf("%s\t%s\n\n", "Number", "GPA");
  
  for (int count = 0; count < 10; count++) {
    printf("%d\t%d\n", count + 1, GPA[count]);
  }
  puts("");
}
