#include <stdio.h>

typedef struct {
  char *firstName;
  char *lastName;
  char *gender;
  int birthDay, birthMonth, birthYear;
  double height, weight;
} HealthProfile;

HealthProfile * data(char *first);

int main(void)
{
  char *FirstName, *LastName, *Gender;
  int age, BirthDay, BirthMonth, BirthYear, maxRate = 0, targetRate = 0;
  double bmi, Height, Weight;
  HealthProfile *variablePtr;

  puts("\n** Health Profile Creation Program **");

  printf("\n%s\n\n%s", "Enter date of birth (dd/mm/yyyy)", "> ");
  scanf("%d/%d/%d", &BirthDay, &BirthMonth, &BirthYear);

  printf("\n%s\n\n%s", "Enter height", "> ");
  scanf("%lf", &Height);

  printf("\n%s\n\n%s", "Enter weight", "> ");
  scanf("%lf", &Weight);
  variablePtr = data(FirstName);
  variablePtr = setData(FirstName, LastName, Gender, BirthDay,
  			BirthMonth, BirthYear, Height, Weight);
  age = ageYears(variablePtr);
  heartRate(&maxRate, &targetRate, age);
  bmi = bodyMassIndex(variablePtr);

  printf("Address: %p\n", variablePtr);  

  printf("\n%s%s\n", "First Name: ", (*variablePtr).firstName);
  
  printf("\n%s%s\n%s%s\n%s%s\n%s%d\n%s%d\n%s%d\n%s%lf\n%s%lf\n",
  	 "First name: ", (*variablePtr).firstName,
  	 "Last name: ", (*variablePtr).lastName,
  	 "Gender: ", (*variablePtr).gender,
  	 "Birth day: ", (*variablePtr).birthDay,
  	 "Birth month: ", (*variablePtr).birthMonth,
  	 "Birth year: ", (*variablePtr).birthYear,
  	 "Height: ", (*variablePtr).height,
  	 "Weight: ", (*variablePtr).weight);
}
HealthProfile * data(char *first)
HealthProfile * setData(char *first, char *last, char *sex,
			int day, int month, int year,
			double heightValue, double weightValue)
{
  static HealthProfile profile;
  HealthProfile *profilePtr;

  profilePtr = &profile;

  profile.firstName = first;
  profile.lastName = last;
  profile.gender = sex;
  profile.birthDay = day;
  profile.birthMonth = month;
  profile.birthYear = year;
  profile.height = heightValue;
  profile.weight = weightValue;
  printf("%s%s\n", "Test: ", profile.firstName);
  printf("%s%s\n", "Test: ", profile.lastName);
  printf("%s%s\n", "Test: ", profile.gender);
  printf("%s%d\n", "Test: ", profile.birthDay);
  printf("%s%d\n", "Test: ", profile.birthMonth);
  printf("%s%d\n", "Test: ", profile.birthYear);
  printf("%s%lf\n", "Test: ", profile.height);
  printf("%s%lf\n", "Test: ", profile.weight);

  printf("Address: %p\n", profilePtr);    
  return profilePtr;
}

int ageYears(HealthProfile * variablePtr)
{
  int currentDay = 9, currentMonth = 10, currentYear = 2018;
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
	 totalYears );

  return ageYears;
}

void heartRate(int *maxRate, int *targetRate, int age)
{
  *maxRate = 220 - age;

  printf( "Age (in years): %f", age);
  printf( "Maximum heart rate: %d.\n", *maxRate);
  printf( "Target rate range: %f to %f.\n", .5 * *maxRate, .85 * *maxRate);
}

double bodyMassIndex(HealthProfile * variablePtr)
{
  double BMI;
  double heightValue = variablePtr->height;
  double weightValue = variablePtr->weight;

  BMI = weightValue / ( heightValue * heightValue );

  printf( "Your BMI is: \n%lf\n", BMI );
  printf("%s\n%s\n%s\n%s\n%s\n", "BMI VALUES", "Underweight:\tless than 18.5",
	 "Normal:\t\tbetween 18.5 and 24.9", "Overweight:\tbetween 25 and 29.9",
	 "Obese:\t\t30 or greater" );

  return BMI;
}
