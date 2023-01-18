#include <stdio.h>
#include <math.h>
#define _USE_MATH_DEFINES 3.14152963
#define SIZE 1

int * array(int radius, float alpha, float beta);

int main(void)
{
  int radius = SIZE;
  float *sphere;
  float alpha = 2 * M_PI, beta = 2 * M_PI;
  float radius_element;
  float alpha_element;
  float beta_element;
  
  sphere = array(radius, alpha, beta);

  for (int i = 0; i <= beta; i += (beta / 10)) {

    for (int j = 0; j <= alpha; j += (alpha / 10)) {

      for (int k = 0; k <= radius; k += (radius / 10)) {
	radius_element = k;
	alpha_element = j;
	beta_element = i;

	printf("array[%.2f][%.2f][%.2f] = %f\n", beta_element, alpha_element, radius_element, *sphere);
      }
    }
  }
}

int * array(int radius, float alpha, float beta)
{
  static int sphere[SIZE][SIZE][SIZE];
  
  for (int i = 0; i <= radius; i++) {

    for (int j = 0; j <= radius; j++) {

      for (int k = 0; k <= radius; k++) {
	sphere[i][j][k] = 1;
      }
    }
  }
  return sphere;
}
