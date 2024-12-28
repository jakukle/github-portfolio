#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
  unsigned long long a, b, t, ab;

  cout <<"Podaj pierwsza liczbe : ";
  cin >> a;
  cout <<"Podaj druga liczbe : "; 
  cin>> b;
  ab = a * b;
  while( b )
  {
    t = b;
    b = a % b;
    a = t;
  }
  ab /= a;
  cout << "NWW = ";
  cout << ab << endl;
  return 0;
} 
