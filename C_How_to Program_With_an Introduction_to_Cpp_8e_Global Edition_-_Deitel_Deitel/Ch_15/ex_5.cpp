//  ************************************************
//  *
//  *    ex_5.cpp
//  *    Author: Wade Shiell
//  *
//  ************************************************

#include <iostream>
using namespace std;

inline double rectArea(const double length, const double width)
{
  return length * width;
}

int main()
{
  double length, width;
  
  cout << "Enter the length of a rectangle: " << endl;
  cin >> length;

  cout << "Enter the width of a rectangel: " << endl;
  cin >> width;

  cout << "The area of the rectangle is " << rectArea(length, width) << endl;
}
