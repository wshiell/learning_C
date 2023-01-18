#include <stdio.h>

int main(void)
{
  int food, entertainment, transportation, medical, household, fuel;
  float rate = .3k, fairTax, totalTax = 0;
  
  puts("FairTax Estimator (press -1 to quit)");

  puts("Enter amount spent on food:");
  scanf("%d", &food);

  fairTax = rate * food;
  totalTax += fairTax;
    
  puts("Enter amount spent on entertainment:");
  scanf("%d", &entertainment);

  fairTax = rate * entertainment;
  totalTax += fairTax;
    
  puts("Enter amount spent on transportation:");
  scanf("%d", &transportation);
      
  fairTax = rate * transportation;
  totalTax += fairTax;
    
  puts("Enter amount spent on medical:");
  scanf("%d", &medical);
      
  fairTax = rate * medical;
  totalTax += fairTax;    
    
  puts("Enter amount spent on household:");
  scanf("%d", &household);
      
  fairTax = rate * household;
  totalTax += fairTax;    
    
  puts("Enter amount spent on fuel:");
  scanf("%d", &fuel);
      
  fairTax = rate * fuel;
  totalTax += fairTax;    

  puts("");

  puts("Total FairTax paid is: ");
  printf("%f", totalTax);
  puts("");
}
