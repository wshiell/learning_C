#include <stdio.h>
#include <math.h>

double calculateCharge(int hours);

int main(void) {

  double totalCharge = 0, rentalCharge;
  int  totalHours = 0, hours, hours1, hours2, hours3;

  puts("Enter hours for car #1:");
  scanf("%d", &hours1);

  puts("Enter hours for car #2:");
  scanf("%d", &hours2);

  puts("Enter hours for car #3:");
  scanf("%d", &hours3);
  
  printf("%s\t%s\t%s\n", "Car", "Hours", "Charge");

  for (int car = 1; car <= 3; car++) {
    
    switch (car) {
    case 1:
      totalHours += hours1;
      rentalCharge = calculateCharge(hours1);
      totalCharge += rentalCharge;
      totalCharge += calculateCharge(hours1);
      printf("%d\t%d\t%.2f\n", car, hours1, rentalCharge);
      break;
    case 2:
      totalHours += hours2;
      rentalCharge = calculateCharge(hours2);
      totalCharge += rentalCharge;
      printf("%d\t%d\t%.2f\n", car, hours2, rentalCharge);
	break;
    case 3:
      totalHours +=hours3;
      rentalCharge = calculateCharge(hours3);
      totalCharge += rentalCharge;
      printf("%d\t%d\t%.2f\n", car, hours3, rentalCharge);
      break;
    }
  }

    printf("%s\t%d\t%.2f\n", "Total", totalHours, totalCharge);
}

double calculateCharge(int hours)
{
  float minimumFee = 25.00, hourlyFee = 5.00, dailyFee = 50.00, tax = .5;
  float rentalCharge = 0;
  int maxRentalTime = 72, days;

  if (hours <= 24) {

    if (hours <= 8) {
      return  rentalCharge = 25.00 + hours * tax;
    }
    else {
    
      if (8 <= hours <= 24) {
	rentalCharge = 25.00 + hourlyFee * (hours - 8) + hours * tax;

	if ((rentalCharge - hours * tax) > 50) {
	  return rentalCharge = 50.00 + hours * tax;
	}
	else {
	  return rentalCharge;
	}
      }
    }
  }
  else {

    if (hours <= 72) {
      days = ceil((float) hours / 24);
      return rentalCharge = dailyFee + 24 * tax * days;
    }
    else {
      puts("\n*****Rental period exceeded. Contact customer*****\n");
      return 0;
    }
  }
}

