#include <stdio.h>

typedef struct {
  char *firstName;
  char *lastName;
  char *gender;
  int birthDay, birthMonth, birthYear;
  double height, weight;
} HealthProfile;

HealthProfile * setData(char first[20], char last[20], char gender[2],
			int BirthDay, int BirthMonth, int BirthYear,
			double Height, double Weight, HealthProfile *variablePtr);
int ageYears(HealthProfile * variablePtr);
void heartRate(int *maxRate, int *targetRate, int age);
double bodyMassIndex(HealthProfile * variablePtr);
void printStruct(HealthProfile * variablePtr);

int main(void)
{
  char FirstName[20], LastName[20], Gender[2];
  int age, BirthDay, BirthMonth, BirthYear, maxRate = 0, targetRate = 0;
  double bmi, Height, Weight;
  HealthProfile *variablePtr, hp = {};
  variablePtr = &hp;
  
  puts("\n** Health Profile Creation Program **");

  printf("\n%s\n\n%s", "Enter First Name", "> ");
  scanf("%s", FirstName);

  printf("\n%s\n\n%s", "Enter Last Name", "> ");
  scanf("%s", LastName);

  printf("\n%s\n\n%s", "Enter Gender (M/F)", "> ");
  scanf("%s", Gender);

  printf("\n%s\n\n%s", "Enter date of birth (dd/mm/yyyy)", "> ");
  scanf("%d/%d/%d", &BirthDay, &BirthMonth, &BirthYear);

  printf("\n%s\n\n%s", "Enter Height (m)", "> ");
  scanf("%lf", &Height);

  printf("\n%s\n\n%s", "Enter Weight (kg)", "> ");
  scanf("%lf", &Weight);

  variablePtr = setData(FirstName, LastName, Gender, BirthDay, BirthMonth, BirthYear,
			Height, Weight, variablePtr);

  age = ageYears(variablePtr);
  heartRate(&maxRate, &targetRate, age);
  bmi = bodyMassIndex(variablePtr);
  printStruct(variablePtr);  
}

HealthProfile * setData(char first[20], char last[20], char gender[2],
			int BirthDay, int BirthMonth, int BirthYear,
			double Height, double Weight, HealthProfile *variablePtr)
{
  variablePtr->firstName = first;
  variablePtr->lastName = last;
  variablePtr->gender = gender;
  variablePtr->birthDay = BirthDay;
  variablePtr->birthMonth = BirthMonth;
  variablePtr->birthYear = BirthYear;  
  variablePtr->height = Height;
  variablePtr->weight = Weight;  

  return variablePtr;
}

int ageYears(HealthProfile * variablePtr)
{
  int currentDay = 27, currentMonth = 1, currentYear = 2019;
  int totalDays, totalMonths, totalYears;
  int birthDay = variablePtr->birthDay;
  int birthMonth = variablePtr->birthMonth;
  int birthYear = variablePtr->birthYear;
  int day, month, year;
  int ageDays, ageMonths, ageYears;
  int days, daysMonth, daysYear;
  float currentAge;

  if (currentDay < birthDay ) {
    month = currentMonth - 1;
    day = birthDay - currentDay;
  }
  else {
    totalDays = currentDay - birthDay;
  }

  if (currentMonth < birthMonth ) {
    year = currentYear - 1;
    month = birthMonth - currentMonth;
  }
  else{
    totalMonths = currentMonth - birthMonth;
  }

  currentMonth = month;
  currentYear = year;
  totalYears = currentYear - birthYear;
  totalMonths = month;
  totalDays = day;

  currentAge = ( float ) days / 365.24;

  printf("\nAge in (days/months/years): %d/%d/%d/\n", totalDays, totalMonths,
	 totalYears);

  return 38;
}

void heartRate(int *maxRate, int *targetRate, int age)
{
  *maxRate = 220 - age;

  printf("\n%s%d\n%s%d\n%s%.1lf%s%.1lf\n",
	 "Age (in years): ", age,
	 "Maximum heart rate: ", *maxRate,
	 "Target rate range: ", .5 * *maxRate, " to ", .85 * *maxRate);
}

double bodyMassIndex(HealthProfile * variablePtr)
{
  double BMI;
  double heightValue = variablePtr->height;
  double weightValue = variablePtr->weight;

  BMI = weightValue / ( heightValue * heightValue );

  printf("\n%s\t%.1lf\n%s\n%s\t%s%.1lf\n%s\t\t%s%.1lf%s%.1lf\n%s\t%s%.1lf%s%.1lf\n%s\t\t%.1lf%s\n",
	 "Your BMI is: ", BMI,
	 "BMI VALUES",
	 "Underweight:", "less than: ", 18.5,
	 "Normal:", "between ", 18.5, " and ", 24.9,
	 "Overweight:", "between ", 25.0, " and ", 29.9,
	 "Obese:", 30.0, " or greater.");

  return BMI;
}
void printStruct(HealthProfile * variablePtr)
{
  printf("\n%s%s\n%s%s\n%s%s\n%s%d/%d/%d\n%s%.2lfm\n%s%.1lfkg\n",
	 "First Name: ", variablePtr->firstName,
	 "Last Name: ", variablePtr->lastName,
	 "Gender: ", variablePtr->gender,
	 "DOB: ", variablePtr->birthDay, variablePtr->birthMonth, variablePtr->birthYear,
	 "Height: ", variablePtr->height,
	 "Weight: ", variablePtr->weight);
}
