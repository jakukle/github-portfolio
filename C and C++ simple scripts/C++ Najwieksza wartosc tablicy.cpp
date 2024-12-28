#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	cout <<"Program ktory szuka najwiekszej wartosci w tablicy "<< endl;
	int a, tab[100];
	cout <<"Podaj ilosc elementow tablicy :::::::::: ";
	cin >> a;
for (int i=0; i<a; i++)
{
	cout << endl;
	cout <<"Podaj kolejny element tablicy : ";
	cin >> tab[i];
	if (tab[i]>tab[i-1])
	{
		cout << "To jest tymczasowy najwiekszy element tablicy : ";
	}
	else 
	{
	cout <<"Mniejszy albo rowny poprzedniemu, a wiec dalej ";
	tab[i] = tab[i-1];
    }
    cout <<tab[i];
    cout << endl;

}
	system ("pause");
	return EXIT_SUCCESS;	
}
