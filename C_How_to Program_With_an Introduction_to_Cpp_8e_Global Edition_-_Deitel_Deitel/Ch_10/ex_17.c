#include <stdio.h>

void mystery(void);

int main(void)
{
  mystery();
}

void mystery(void)
{
  unsigned int mask = 1 << 31;
  unsigned int total;

  for (unsigned int h = 1; h <= 1000; h++) {

    int bits = h;
    total = 0;
    
    for (unsigned int i = 1; i <= 32; ++i, bits <<= 1) {

      if ((bits & mask) == mask) {
	++total;
      }
    }
  }
  puts("");
}
