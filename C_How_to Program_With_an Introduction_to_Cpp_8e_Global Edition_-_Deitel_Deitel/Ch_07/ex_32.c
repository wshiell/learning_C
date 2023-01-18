#include <stdio.h>

void displayResults(char *causes[5], int responses[][10]);
void average(int row, int responses[][10]);

int main(void)
{
  char *causes[5] = { "War", "Famine", "Disease", "Flood", "Pestilence" };
  int responses[5][10] = {0};
  int person = 1;
  int survey = 0;

  puts("\n*** Social Consciousness Survey ***\n");
  puts("Indicate how important you perceive the following causes"
       "\n(1 being unimportant, 10 being of absolute importance)");

  while (survey != -1) {

    printf("\nPerson #%d:\n", person);

    for (size_t i = 0; i < 5; i++) {

      int choice;

      printf("\nHow important do you consider %s?\n", causes[i]);
      printf("\n%s", "> ");
      scanf("%d", &choice);
      responses[i][choice - 1]++;
    }
    puts("\nWould you like to run the survey again?\n(1 for yes, -1 for no)\n");
    scanf("%d", &survey);
    printf("\n%s\n", "> ");
    person++;
  }
  displayResults(causes, responses);
}

void displayResults(char *causes[5], int responses[][10])
{
  printf("\n%-12s", "Causes");

  for (int count = 1; count <= 10; count++) {

    printf("%3d", count);
  }
  puts("");
  
  for (int count = 0; count < 42; count++) {

    printf("%s", "-");
  }
  puts("");

  for (size_t row = 0; row < 5; row++) {

    printf("%-12s", causes[row]);
    
    for (size_t column = 0; column < 10; column++) {

      printf("%3d", responses[row][column]);
    }
    average(row, responses);
  }
  puts("");
}

void average(int row, int responses[][10])
{
  int total = 0;
  int people = 0;
  double average;
  
  for (size_t column = 0; column < 10; column++) {

    if (responses[row][column] != 0) {
      total += column * responses[row][column] + 1;
    }
    else {
      ;
    }
    people += responses[row][column];
  }

  average = (double) total / people;
  printf("  Average: %.2lf\n", average);
}
