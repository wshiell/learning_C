#include <stdio.h>

typedef struct {
  int a;
  char *lol;
} Fancy;

typedef struct {
  int z;
} Plain;

int main(void)
{
  char *a;
  int *b;
  double *c;
  long double *d;

  Fancy fancyStruct = {2, "Hi"}, *fancyPtr = NULL;

  fancyPtr = &fancyStruct;
  
  printf("%-50s%ld\n%-50s%ld\n%-50s%ld\n%-50s%ld\n",
	 "The size of a pointer of type char * is: ", sizeof(a),
         "The size of a pointer of type int * is: ", sizeof(b),
	 "The size of a pointer of type double * is: ", sizeof(c),
	 "The size of a pointer of type long double * is: ", sizeof(d));

  printf("%s%d\n%s%s\n",
	 "Struct member #1 structure pointer operator  is: ", fancyPtr->a,
	 "Struct member #2 structure pointer operator is: ", fancyPtr->lol);
  printf("%s%d\n%s%s\n",
	 "Struct member #1 using structure member operator is: ", fancyStruct.a,
	 "Struct member #2 structure member operator is: ", fancyStruct.lol);
}
