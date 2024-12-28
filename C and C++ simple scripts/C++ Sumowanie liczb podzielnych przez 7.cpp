#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	cout << "Program sumujacy elementy podzielne przez 7" << endl;
	int n, tab[20], suma=0;
cout << "Podaj ilosc elementow w tablicy (STWORZONA TABLICA MOZE MIEC MAKS 20)";
    cout << endl;
	cin >> n;
	if (n<=0)
	{
		cout << "BLAD - JEST MNIEJ NIZ JEDEN ELEMENT" << endl;
	}
	else if(n==1)
	{
		cout << "Podales " << n << " element" << endl;
	}
	else if(n>1 && n<5)
	{
		cout << "Podales " << n << " elementy" << endl;
	}
	else cout << "Podales " << n << " elementow" << endl;
	for (int i=0; i<n; i++)
{
	 cout << "Podaj liczbe : ";
	 cin >> tab[i];
	 cout << "Podales liczbe : " << tab[i] << endl;	
	if (tab[i]%7==0)
	 cout << "Liczba ta jest podzielna przez 7" << endl;
	else cout <<"Ta liczba nie jest podzielna przez 7" << endl;
	   if (tab[i]%7==0)
	{
		    suma = suma + tab[i];
            cout<<"Aktualna suma liczb podzielnych przez 7 wynosi "<<suma<<endl;
	}
	   else cout <<"LECIMY DALEJ"<< endl;
	  	  

}
          cout << "==========" << endl;
          cout << "KONCOWA SUMA WYNOSI : " << suma << endl;
	
	system ("pause");
	return EXIT_SUCCESS;
}
