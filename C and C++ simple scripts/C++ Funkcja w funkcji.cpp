#include <iostream>
#include <cstdlib>

using namespace std;

int function(int a);
int fun(int a);

int main()
{
	int x, b;
	cout <<"Podaj liczbe do obliczen ";
	cin >>x;
	cout <<"Wybierz dzialanie : 1 - mnozenie, 2 - dodawanie ";
	cin >>b;
	int zmienna = function(x);
	int szymon = fun(x); 
switch (b)
 {
       case 1:
        cout << function(x);
       break;

       case 2:
        cout << szymon;
       break;

       default:
        cout << "BLAD";
       break;
 }
 getchar();
 return 0;
}

int function(int a)
{
	   return a*a;
     }
    
int fun(int a)
{
	   return a+a;
     }
     

     
