#include <stdio.h>
#include <math.h>

#define PI 3.141592653

void circumference(double radius);
void area(double radius);
void volume (double radius);

int main(void)
{
  int choice;
  double radius;
  void (*circle[3])(double) = { circumference, area, volume };

  puts("Enter value for radius:");
  scanf("%lf", &radius);

  puts("To print circumference, enter 0.");
  puts("To print surface area, enter 1.");
  puts("To print volume, enter 2.");
  puts("To quit, enter 3.");
  scanf("%d", &choice);

  while (choice != 3) {
    (*circle[choice])(radius);
    puts("\nTo print circumference, enter 0.");
    puts("To print surface area, enter 1.");
    puts("To print volume, enter 2.");
    puts("To quit, enter 3.");
    scanf("%d", &choice);
  }
  puts("Program execution terminated.");
}

void circumference(double radius)
{
  double circumference;

  circumference = 2 * PI * radius;
  printf("\nCircumference: %.2lf\n", circumference);
}

void area(double radius)
{
  double area;

  area = 4 * PI * pow(radius, 2);
  printf("\nSurface area: %.2lf\n", area);
}

void volume(double radius)
{
  double volume;

  volume = (4 * PI * pow(radius, 3)) / 3;
  printf("\nVolume: %.2lf\n", volume);
}
