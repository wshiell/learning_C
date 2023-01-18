#include <stdio.h>
#include <math.h>

void roots(float a, float b, float c);

int main(void)
{
  float a, b, c;

  puts("Enter the coefficient for x^2:");
  scanf("%f", &a);

  puts("Enter the coefficient for x:");
  scanf("%f", &b);

  puts("Enter the value of c:");
  scanf("%f", &c);

  roots(a, b, c);
}

void roots(float a, float b, float c)
{
  float x_1, x_2;
  float discriminant = pow(b, 2) - 4 * a * c;

  if (discriminant < 0) {
    printf("The quadratic equation %.2fx^2 + %.2fx + %.2f has no real roots",
	   a, b, c);
    puts("");
  }
  else {
    x_1 = (-1 * b + sqrt(discriminant)) / (2 * a);
    x_2 = (-1 * b - sqrt(discriminant)) / (2 * a);

    printf("The roots of the quadratic equation %.2fx^2 + %.2fx + %.2f are: "
	   "\n", a, b, c);
    printf("%.2f and %.2f", x_1, x_2);
    puts("");
  }
}
