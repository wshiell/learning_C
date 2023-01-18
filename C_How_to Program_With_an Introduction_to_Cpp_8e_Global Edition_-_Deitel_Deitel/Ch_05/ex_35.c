#include <stdio.h>

long long int fibonacci(int number);

int main(void)
{
  int number;
  long long int fibonacci_n;

  puts("Enter an integer:");
  scanf("%d", &number);

  fibonacci_n = fibonacci(number);

  printf("Fibonacci #%d is: %lld\n", number, fibonacci_n);
}

long long int fibonacci(int number)
{
  long long int fibonacci = 0;
  int fibonacci1, fibonacci2;

  if (number == 1) {
    fibonacci = 0;
    return fibonacci;
  }
  else {

    if (number == 2) {
      fibonacci = 1;
      return fibonacci;
    }
    else {

      if (number > 2) {
        fibonacci1 = 0;
        fibonacci2 = 1;

        for (int count = 1; count < number - 1; count++) {
          fibonacci = fibonacci1 + fibonacci2;
          fibonacci1 = fibonacci2;
          fibonacci2 = fibonacci;
        }
      return fibonacci;
      }
    }
  }
}
