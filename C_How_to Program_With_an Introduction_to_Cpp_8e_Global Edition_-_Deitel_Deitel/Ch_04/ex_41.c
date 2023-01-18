#include <stdio.h>

int main(void)
{
  float initialPopulation = 7.2, change;
  float growthRate = 0.011, previousPopulation, currentPopulation;
  int doubled, count = 0;
  
  printf("%20s%20s%20s\n", "Year", "Population in Year", "Population Change");
  puts("************************************************************\n");
  printf("%20s%20f%20s\n", "0", currentPopulation, "-");

  currentPopulation = initialPopulation;
  
  for (int year = 1; year <= 75; year++) {
    
    previousPopulation = currentPopulation;
    currentPopulation += currentPopulation * growthRate;

    change = currentPopulation - previousPopulation;

    printf("%20d%20f%20f\n", year, currentPopulation, change);

    if (currentPopulation > 2 * initialPopulation) {
      if (count == 0) {
      doubled = year;
      count++;
      }
      }
  }
      printf("\nPopulation doubled in year %d\n", 2018 + doubled);
}
