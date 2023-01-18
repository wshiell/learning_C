//  ************************************************
//  *
//  *    ex_6.cpp
//  *    Author: Wade Shiell
//  *
//  ************************************************

#include <iostream>
using namespace std;

int multipleByValue(int count);
void multipleByReference(int &count);

int main()
{
  int count = 3;

  cout << "Variable 'count' before function call is " << count << endl;    
  cout << "Variable 'count' multiplied by value is " << multipleByValue(count) << endl;
  cout << "Variable 'count' after function call is " << count << endl;  
  cout << "Variable 'count' before function call is " << count << endl;      

  multipleByReference(count);

  cout << "Variable 'count' multiplied by reference is " << count << endl;
  cout << "Variable 'count' after function call is " << count << endl;    
}

int multipleByValue(int count)
{
  return count * count;
}

void multipleByReference(int &count)
{
  count *= count;
}
