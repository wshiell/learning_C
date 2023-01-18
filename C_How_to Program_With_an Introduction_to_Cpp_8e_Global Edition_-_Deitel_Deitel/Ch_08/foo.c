#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  double d, e, f;
  const char *s1 = "1.27 10.3 9.432";
  
  sscanf("1.27 10.3 9.432", "%lf %lf %lf", &d, &e, &f);
  printf("%.2lf %.1lf %.3lf\n", d, e, f);
}
