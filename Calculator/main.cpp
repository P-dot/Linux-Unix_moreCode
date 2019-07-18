#include <iostream>
using namespace std;
#include "calculator.cpp"
int main()
{
  system ("clear");
  Calc a;
  string s = "q";
  while (s != "exit")
  {
  	cout << "MATH:> ";
  	cin >> s;
  	a.Operation(s);
  }
  return 0;
}



