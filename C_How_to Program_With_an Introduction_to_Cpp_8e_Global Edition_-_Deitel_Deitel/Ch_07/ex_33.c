#include <stdio.h>

void bicycle(void);
void car(void);
void building(void);

int main(void)
{
  int choice;
  void (*footprint[3])(void) = { bicycle, car, building };

  puts("\n*** Carbon Footprint Calculator ***\n");
  puts("Enter the type of carbon footprint to calculate\n"
       "(1 for bicycle, 2 for car, 3 for building, -1 to quit)\n");
  printf("%s", "> ");
  scanf("%d", &choice);

  while (choice != -1) {

    footprint[choice - 1]();

    puts("Enter the type of carbon footprint to calculate\n"
	 "(1 for bicycle, 2 for car, 3 for building, -1 to quit)\n");
    printf("%s", "> ");
    scanf("%d", &choice);
  }
  puts("\nRemember to love the earth, and the Earth will love you. Peace out man!");
  puts("\n** Program Terminated **\n");
}

void bicycle(void)
{
  int travelDistance;

  puts("\nEnter travel distance:");
  scanf("%d", &travelDistance);
  
  printf("\nBicycles use people power - the have no carbon footprint :)\n\n");
}

void car(void)
{
  int travelDistance;
  double fuelEfficiency = 15;
  double totalFuel;
  double emissionsPerLitre = 2.31;
  double vehicleEmissions;

  puts("\nEnter travel distance:");
  scanf("%d", &travelDistance);
  
  totalFuel = travelDistance / fuelEfficiency;
  vehicleEmissions = totalFuel * emissionsPerLitre;

  printf("\nDistance travelled: %d\nFuel Efficiency: %.2lf\nFuel used: %.2lf\n"
	 "Emissions per litre: %.2lf\nEmissions for vehicle: %.2lf\n\n",
	 travelDistance, fuelEfficiency, totalFuel, emissionsPerLitre,
	 vehicleEmissions);
}

void building(void)
{
  int timeOccupied;
  double averagePowerPerHour = 13;
  double totalPowerUsed;
  double coalBurnedPerKilowatt = 14;
  double totalMassCoal;
  double emissionsPerKg = 25;
  double buildingEmissions;

  puts("\nEnter time spent in building:");
  scanf("%d", &timeOccupied);

  totalPowerUsed = timeOccupied * averagePowerPerHour;
  totalMassCoal = totalPowerUsed / coalBurnedPerKilowatt;
  buildingEmissions = totalMassCoal * emissionsPerKg;

  printf("\nTime in building: %d\nAverage Power consumption (per hour): %.2lf\n"
	 "Total power used: %.2lf\nCoal burned per kW: %.2lf\nTotal Mass of Coal: %.2lf\n"
	 "Emissions per kg of Coal: %.2lf\nTotal building emissions: %.2lf\n\n",
	 timeOccupied, averagePowerPerHour, totalPowerUsed, coalBurnedPerKilowatt,
	 totalMassCoal, emissionsPerKg, buildingEmissions);
}
