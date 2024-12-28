#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	cout << "Program do obliczania iloczynu elementow podanych w tablicy" << endl;
	long long n, tab[10], iloczyn=1;
	cout << "Podaj ilosc elementow tablicy (zadeklarowana tablica moze pomiescic maks 10 elementow)"<<endl;
	cin >> n;
	if (n<=0 || n>10)
	{
		cout << "Musza byc jakies elementy w tablicy,ale nie moze byc ich za duzo (min 1 element)" << endl;
		cout << "Podaj jeszcze raz (maks 10 elementow)" << endl;
		cin >> n;
		if (n<=0 || n>10)
		{
			cout << "Jak nie chczesz to konczymy ta zabawe - KONIEC PROGRAMU" << endl; 
			exit (0);
		}
	    else cout << "Podales " << n << " element/y/ow"<< endl;
	}
	else cout << "Podales " << n << " element/y/ow"<< endl;
	
	cout << "Teraz bedziemy deklarowac wartosc kazdego elementu tablicy" << endl;
	
for (int i=0, j=1; i<n; i++)
	{
	   cout <<"Podaj wartosc " << j <<" elementu" << endl;
	   cin >> tab[i];
	   if (tab[i]==0) 
	   {
	   cout <<"Na pewno chczesz podawac 0? Iloczyn bedzie juz na pewno rowny 0 - Podaj jeszcze raz" <<endl;
	   cin >> tab[i];
	      if (tab[i]==0) {
	      	cout <<"Znowu podales zero a WIEC ILOCZYN ROWNA SIE 0" << endl;
	        exit (0);
			}
	      else cout <<"Wartosc " << j << " elementu rowna sie " << tab[i] << endl;
	   }
	   else cout <<"Wartosc " << j << " elementu rowna sie " << tab[i] << endl;
	   j++;
	   iloczyn = iloczyn * tab[i];
	   if ((i+1)<n)
	   cout << "TYMCZASOWY ILOCZYN ROWNA SIE : " << iloczyn << endl;
	   else cout <<"=========="<<endl;  	
	}
	
	cout << "OSTATECZNY ILOCZYN WYNOSI " << iloczyn << endl;
	
	system ("pause");
	return EXIT_SUCCESS;
}
