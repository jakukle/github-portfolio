#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;
int main()
{
	cout << "Program wyszukujacy rozwiazania rownania kwadratowego\n";
	float a,b,c,delta,xjeden,xdwa,xzero;
	cout << "Podaj wspolczynnik przy x do kwadratu : ";
	cin >> a;
	cout << "Podaj wspolczynnik przy x : ";
	cin >> b;
	cout << "Podaj wyraz wolny : ";
	cin >> c;
	delta = (b*b) - (4*a*c);
	cout << "Delta rowna sie : "<<delta <<"\n";
if (delta<0)
{
	   cout << "Delta mniejsza od 0 - brak rozwiazan\n";
}
 else if(delta>0)
 {
	   xjeden = -(b+sqrt(delta))/(2*a);
	   cout << "pierwszy pierwiastek rownania rowna sie : "<<xjeden <<"\n";
	   xdwa = (-b+sqrt(delta))/(2*a);
	   cout << "drugi pierwiastek rownania rowna sie : "<<xdwa << "\n";
 }
  else 
  {
       cout << "Delta rowna sie zero";
       xzero = -b/(2*a);
       cout << ", a jedyny pierwiastek rownania rowna sie : "<<xzero<<"\n"; 
  }

	system ("PAUSE");
	return 0;
}
