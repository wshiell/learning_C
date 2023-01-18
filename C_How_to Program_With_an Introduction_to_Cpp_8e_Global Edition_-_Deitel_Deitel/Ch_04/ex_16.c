#include <stdio.h>

int main(void)
{

  for (unsigned int counter = 1; counter <=10; counter++) {

    for (unsigned int tally = 1; tally <= counter; tally++) {
      printf("%s", "*");
    }
    puts("");
  }
  puts("");

  for (unsigned int counter = 1; counter <=10; counter++) {

    for (unsigned int tally = 10; tally >= counter; tally--) {
      printf("%s", "*");
    }
    puts("");
  }
  puts("");
  
   for (unsigned int counter = 1; counter <=10; counter++) { 

     for (unsigned int tally = 2; tally <= counter; tally++) { 
       printf("%s", " ");
     }

     for (unsigned int total = 10; total >= counter; total--) {
       printf("%s", "*");
     }
     puts(""); 
   } 
   puts("");
   
   for (unsigned int counter = 1; counter <=10; counter++) { 

     for (unsigned int tally = 10; tally > counter; tally--) { 
       printf("%s", " ");
     }

     for (unsigned int total = 1; total <= counter; total++) {
       printf("%s", "*");
     }
     puts(""); 
   } 
   puts("");
}
