//  ************************************************
//  *
//  *    ex_9.cpp
//  *    Author: Wade Shiell
//  *
//  ************************************************

#include <iostream>
#include "numSwap.h"
using namespace std;

int main()
{
  int num1, num2;
  double doub1, doub2;

  cout << "Enter two integers: " << endl << "> ";
  cin >> num1 >> num2;
  
  cout << "Enter two doubles: " << endl << "> ";
  cin >> doub1 >> doub2;

  cout << "First & second integers before function call: " << num1 << " & " << num2 << endl;
  numSwap(num1, num2);
  cout << "First & second integers after function call: " << num1 << " & " << num2 << endl;
  
  cout << "First & second doubles before function call: " << doub1 << " & " << doub2 << endl;
  numSwap(doub1, doub2);
  cout << "First & second doubles after function call: " << doub1 << " & " << doub2 << endl;
  
}

