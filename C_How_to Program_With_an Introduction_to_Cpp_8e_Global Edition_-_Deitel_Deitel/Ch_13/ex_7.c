#include <stdio.h>

#define MINIMUM2(x, y) if ((x) < (y)) { printf("%s%d\n", "Minimum = ", (x)); } else {printf("%s%d\n", \
		          "Minimum = ", (y)); }
#define MINIMUM3(x, y, z) if ((x) < (y)) { MINIMUM2(x, z)} else {MINIMUM2(y, z)}

int main(void)
{
  int x, y, z;
  
  puts("Enter three integers:");
  scanf("%d%d%d", &x, &y, &z);

  MINIMUM3(x, y, z);
}
