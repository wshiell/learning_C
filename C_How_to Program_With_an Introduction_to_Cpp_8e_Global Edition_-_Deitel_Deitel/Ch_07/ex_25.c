#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4

void minimum(const int grades[][EXAMS], size_t pupils, size_t tests);
void maximum(const int grades[][EXAMS], size_t pupils, size_t tests);
void average(const int grades[][EXAMS], size_t pupils, size_t tests);
void printArray(const int grades[][EXAMS], size_t pupils, size_t tests);

int main(void)
{
  void (*processGrades[4])(const int a[3][4], size_t, size_t) = { minimum, maximum,
								average, printArray };
  int studentGrades[STUDENTS][EXAMS] =
    { { 77, 68, 86, 73 },
      { 96, 87, 89, 78 },
      {70, 90, 86, 81 } };

  puts("Enter a choice:\n\n"
       "   0  Print the array of grades\n"
       "   1  Find the minimum grade\n"
       "   2  Find the maximum grade\n"
       "   3  Print the average on all tests for each student\n"
       "   4  End program\n"
       "\n> ");

  int choice;
  scanf("%d", &choice);
    
  while (choice != 4) {

    (*processGrades[choice])(studentGrades, STUDENTS, EXAMS);
    puts("\nEnter a choice:\n\n"
	 "   0  Print the array of grades\n"
	 "   1  Find the minimum grade\n"
	 "   2  Find the maximum grade\n"
	 "   3  Print the average on all tests for each student\n"
	 "   4  End program\n"
	 "\n> ");
    scanf("%d", &choice);
  }
}

void minimum(const int grades[][EXAMS], size_t pupils, size_t tests)
{
  int lowGrade = 100;

  for (size_t i = 0; i < pupils; ++i) {

    for (size_t j = 0; j < tests; ++j) {

      if (grades[i][j] < lowGrade) {
	lowGrade = grades[i][j];
      }
    }
  }
  printf("\n\nLowest grade: %d\n", lowGrade);
}

void maximum(const int grades[][EXAMS], size_t pupils, size_t tests)
{
  int highGrade = 0;

  for (size_t i = 0; i < pupils; ++i) {

    for (size_t j = 0; j < tests; ++j) {

      if (grades[i][j] > highGrade) {
	highGrade = grades[i][j];
      }
    }
  }
  printf("Highest grade: %d\n", highGrade);
}
void average(const int grades[][EXAMS], size_t pupils, size_t tests)
{
  for (size_t student = 0; student < pupils; ++student) {

    int total = 0;

    for (size_t i = 0; i < tests; ++i) {
      total += grades[student][i];
    }
    printf("The average grade for student %lu is %.2ld", student, total / tests);
  }
}

void printArray(const int grades[][EXAMS], size_t pupils, size_t tests)
{
  puts("The array is:");
  printf("%s", "                [0]   [1]    [2]   [3]");

  for (size_t i = 0; i < pupils; ++i) {
    printf("\nstudentGrades[%lu] ", i);

    for (size_t j = 0; j < tests; ++j) {
      printf("%-5d", grades[i][j]);
    }
  }
}
