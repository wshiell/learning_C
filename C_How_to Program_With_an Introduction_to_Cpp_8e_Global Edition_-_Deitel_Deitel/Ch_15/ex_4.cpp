#include <iostream>
#include <cmath>
using namespace std;

inline void sphereVolume(double radius)
{
  cout << "Volume = " << (4.0 / 3.0) * 3.14159 * pow(radius, 3) << endl;
}

int main()
{
  double radius;
  
  cout << "Enter the radius of the sphere: " << endl;
  cin >> radius;

  sphereVolume(radius);
}
