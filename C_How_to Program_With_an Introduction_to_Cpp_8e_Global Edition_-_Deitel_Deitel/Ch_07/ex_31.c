#include <stdio.h>

void add(void);
void subtract(void);
void multiply(void);
void divide(void);
double* dataEntry(void);

int main(void)
{
  int choice;
  
  void (*calculator[4])(void) = { add, subtract, multiply, divide };

  puts("Basic Calculator Program.\n\n"
       "Enter 1 to add\nEnter 2 to subtract\n"
       "Enter 3 to multiply\nEnter 4 to divide\n"
       "Enter 0 to quit\n");
  printf("%s", "> ");
  scanf("%d", &choice);

  while (choice != 0) {

    (*calculator[choice - 1])();
    puts("Enter 1 to add\nEnter 2 to subtract\n"
	 "Enter 3 to multiply\nEnter 4 to divide\n"
	 "Enter 0 to quit\n");
    printf("%s", "> ");
    scanf("%d", &choice);
  }
  puts("\nProgram terminated.\n");
}

void add(void)
{
  double *data;
  
  puts("\nAddition:");
  data = dataEntry();
  printf("\n%.2lf + %.2lf = %.2lf\n\n", data[0], data[1], data[0] + data[1]);
}

void subtract(void)
{
  double *data;

  puts("\nSubtraction:");
  data = dataEntry();
  printf("\n%.2lf - %.2lf = %.2lf\n\n", data[0], data[1], data[0] - data[1]);  
}

void multiply(void)
{
  double *data;
  
  puts("\nMultiplication:");    
  data = dataEntry();
  printf("\n%.2lf x %.2lf = %.2lf\n\n", data[0], data[1], data[0] * data[1]);  
}

void divide(void)
{
  double *data;

  puts("\nDivision:");    
  data = dataEntry();
  printf("\n%.2lf / %.2lf = %.2lf\n\n", data[0], data[1], data[0] / data[1]);  
}

double* dataEntry(void)
{
  static double data[2];
  
  puts("\nEnter two numbers:");
  scanf("%lf", &data[0]);
  scanf("%lf", &data[1]);
  
  return data;
}
