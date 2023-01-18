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
			double Height, double Weight);
void printStruct(HealthProfile * variablePtr);

int main(void)
{
  char FirstName[20], LastName[20], Gender[2];
  int age, BirthDay, BirthMonth, BirthYear, maxRate = 0, targetRate = 0;
  double bmi, Height, Weight;
  HealthProfile *variablePtr;
  
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

  variablePtr = setData(FirstName, LastName, Gender, BirthDay, 
                BirthMonth, BirthYear, Height, Weight);


  printf("Address pointer: %p\n", variablePtr);
  printf("Address pointer (deref): %p\n", variablePtr->firstName);
  printf("Address pointer (deref): %p\n", variablePtr->lastName);
  printStruct(variablePtr);
  printf("Address pointer (deref): %p\n", variablePtr->firstName);
  printf("Address pointer (deref): %p\n", variablePtr->lastName);  
  printStruct(variablePtr);
}

HealthProfile * setData(char first[20], char last[20], char gender[2],
			int BirthDay, int BirthMonth, int BirthYear,
			double Height, double Weight)
{
  static HealthProfile profile;
  HealthProfile *profilePtr;

  profilePtr = &profile;

  profile.firstName = first;
  profile.lastName = last;
  profile.gender = gender;
  profile.birthDay = BirthDay;
  profile.birthMonth = BirthMonth;
  profile.birthYear = BirthYear;  
  profile.height = Height;
  profile.weight = Weight;  

  return profilePtr;
}

void printStruct(HealthProfile * variablePtr)
{
  printf("\n%s%s\n%s%s\n%s%s\n%s%d/%d/%d\n%s%.2lfm\n%s%.1lfkg\n",
	 "First Name: ", variablePtr->firstName,
	 "Last Name: ", variablePtr->lastName,
	 "Gender: ", variablePtr->gender,
	 "DOB: ", variablePtr->birthDay, variablePtr->birthMonth,
         variablePtr->birthYear,
	 "Height: ", variablePtr->height,
	 "Weight: ", variablePtr->weight);
}  
