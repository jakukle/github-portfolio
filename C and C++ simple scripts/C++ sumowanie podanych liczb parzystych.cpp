#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
	cout <<"Program sumujacy liczby parzyste sposrod podanych"<<endl;
	int n, tab[100], suma;
	cout <<"Podaj liczbe elementow ";
	cin >> n;
	cout <<"A wiec mamy " << n;
	if (n<0)
	{
		cout <<endl << "NIE MOZE BYC MNIEJ NIZ ZERO ELEMENTOW!!!"<<endl;
	    }
	else if (n==1)
	{
		cout << " element" << endl;
	    }
	else if(n>=2 && n<=4)
	{
		cout << " elementy" << endl;
        }
    else
    {
	    cout << " elementow" << endl;
	}

   cout << "Elementy tablicy " << endl;
   
for (int i=0, tab[i]; i < n; i++)
 {
cout << "Podaj wartosc" <<" ";
cin >>tab[i];
if (tab[i]%2==1)
{
	cout <<"Podano liczbe nieparzysta - zostanie ona pominieta" << endl;
}
else
{
    suma = suma + tab[i];
}
 } 
    cout <<"Szukana suma podanej ilosci liczb parzystych rowna sie: "<< suma;
    
    cout<<endl;
	
		system ("PAUSE");
return EXIT_SUCCESS;	
}
