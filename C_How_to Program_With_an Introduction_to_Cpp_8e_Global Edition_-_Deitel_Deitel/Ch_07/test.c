#include <stdio.h>

int f1(void);
int f2(void);

int main(void)
{
  int (*fns[2])(void) = {f1, f2};
  int choice;
  
  puts("Enter choice:");
  scanf("%d", &choice);

  if (choice == 1){
    printf("%d\n", (*fns[choice]);
  }
  else {
    printf("%d\n", (*fns[choice]));
  }
}

int f1(void)
{
  return 0;
}

int f2(void)
{
  return 1;
}
