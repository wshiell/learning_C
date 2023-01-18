#include <stdio.h>

#define PI 3
#define SPHERE_VOLUME(x) (4.0 / 3.0) * PI * (x) * (x) * (x)

int main(void)
{
  printf("%s\t%s\n\n", "Radius", "Volume");
  
  for (int i = 1; i <= 10; i++) {
    printf("%3d\t", i);    
    printf("%7.2lf", SPHERE_VOLUME(i));
    printf("%s\n", " units^3");
  }
}
