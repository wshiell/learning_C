#include <stdio.h>

union integer {
  char c;
  short s;
  int i;
  long b;
};

int main(void)
{
  union integer object;

  puts("Enter a char value:");
  scanf("%c", &object.c);
  printf("\n%s\n%c\n%hd\n%d\n%ld\n", "object.c: ", object.c, object.c,
	 object.c, object.c);

  puts("Enter a short value:");
  scanf("%hd", &object.s);
  printf("\n%s%c\n%hd\n%d\n%ld\n", "object.s: ", object.s, object.s,
	 object.s, object.s);

  puts("Enter a int value:");
  scanf("%d", &object.i);
  printf("\n%s%c\n%hd\n%d\n%ld\n", "object.i: ", object.i, object.i,
	 object.i, object.i);

  puts("Enter a long value:");
  scanf("%ld", &object.b);
  printf("\n%s%c\n%hd\n%d\n%ld\n", "object.b: ", object.b, object.b,
	 object.b, object.b);
}
