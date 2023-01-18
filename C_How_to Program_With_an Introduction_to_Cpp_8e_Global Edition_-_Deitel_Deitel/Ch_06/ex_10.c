#include <stdio.h>

int salary(int gross);

int main(void)
{
  int number, gross;
  int salaries[9] = {0};

  puts("Enter employee gross sales (-1 to quit):");  
  scanf("%d", &gross);
  
  while (gross != -1) {
    
    int salaryRange = salary(gross);

    if (salaryRange >= 200 && salaryRange <= 299) {
      salaries[0]++;
    }
    else if (salaryRange >= 300 && salaryRange <= 399) {
      salaries[1]++;
    }
    else if (salaryRange >= 400 && salaryRange <= 499) {
      salaries[2]++;
    }
    else if (salaryRange >= 500 && salaryRange <= 599) {
      salaries[3]++;
    }
    else if (salaryRange >= 600 && salaryRange <= 699) {
      salaries[4]++;
    }
    else if (salaryRange >= 700 && salaryRange <= 799) {
      salaries[5]++;
    }
    else if (salaryRange >= 800 && salaryRange <= 899) {
      salaries[6]++;
    }
    else if (salaryRange >= 900 && salaryRange <= 999) {
      salaries[7]++;
    }
    else {
      salaries[8]++;
    }

    puts("Enter employee gross sales (-1 to quit):");
    scanf("%d", &gross);
  }

  for( int count = 0; count < 9; count++) {

    if (count != 8) {
      printf("Number of employees earning between $%d and $%d: %d\n", 200  + (100 * count), 300 + (100 * count) - 1, salaries[count]);
    }
    else {
      printf("Number of employees earning more than $%d: %d\n", 1000, salaries[count]);      
    }
  }
}

int salary(int gross)
{
  int baseSalary = 200;
  int commission = gross * 0.09;
  int salary;

  salary = baseSalary + commission;
  return salary;
}
