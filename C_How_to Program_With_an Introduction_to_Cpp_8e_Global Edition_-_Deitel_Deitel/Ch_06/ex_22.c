#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SALESPEOPLE 4
#define PRODUCTS 5

int main(void)
{
  srand(time(NULL));
  
  // Define array and variables

  int sales[PRODUCTS][SALESPEOPLE] = {0};
  int totalSales;

  // Enter data

  // Day  

  for (int day = 1; day <= 30; day++) {

    // Salesperson
    
    for (int salesperson = 1; salesperson <= 4; salesperson++) {

      // Product
      
      for (int product = 1; product <= 5; product++) {

	//Enter total sales (for product, salesperson, day)

	totalSales = rand() % 100;

	sales[product - 1][salesperson - 1] += totalSales;
      }
    }
  }

  // Print summary header

  printf("%15s", "");
  
  for (int salesperson = 0; salesperson < SALESPEOPLE; salesperson++) {

    printf("%s%-5d", "Salesperson #", salesperson + 1);
  }

  printf("%-30s\n\n", "Total sales (per product)");

  // Print summary per row (products)
  
  for (int row = 0; row < PRODUCTS; row++) {

    int sum = 0;
    
    printf("%s%-15d", "Product #", row + 1);
    
    for (int column = 0; column < SALESPEOPLE; column++) {

      printf("%s%-16d ", "$", sales[row][column]);
      sum += sales[row][column];
    }

    printf("%12s%d\n\n", "$", sum);
  }

  // Print totals for each salesperson
  
  printf("%-15s", "Total Sales");
  printf("\n%-15s", "(per clerk)");

  for (int salesperson = 0; salesperson < SALESPEOPLE; salesperson++) {

    int total = 0;
    
    for (int grossSales = 0; grossSales < PRODUCTS; grossSales++) {

      total += sales[salesperson][grossSales];
    }

    printf("%s%-8d", "         $", total);
    total = 0;
  }

  puts("");
}

