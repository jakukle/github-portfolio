#include<iostream>
#include"Car.h"
#include<ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	
	Car Tab[5];
	string wszystko;
	double max;
	int i,numerWygranego=0;
	for (i = 0; i < 5; i++)
	{
		Tab[i].nadanieNumeru((double)rand() / RAND_MAX * (98) + 1);
	}
	for (i = 0; i < 5; i++)
	{
		Tab[i].tankowanie(0.8 * Tab[i].pobierzPojemnosc());
	}
	for (i = 0; i < 5; i++)
	{
		while (Tab[i].pobierzPaliwo() > 0)
		{
			Tab[i].przejedzDystans(100);
		}
	}
	max = Tab[0].pobierzPrzebieg();
	for (i = 0; i < 5; i++)
	{
		if (Tab[i].pobierzPrzebieg() > max)
		{
			max = Tab[i].pobierzPrzebieg();
			numerWygranego = i;
		}
	}

	for (i = 0; i < 5; i++)
	{
		cout << "Samochod nr." << i + 1 << ":" << endl;
		Tab[i].infoCar(wszystko);
		cout << wszystko<<endl;
		
	}
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "Wygral Samochod nr." << numerWygranego+1<<endl;
	Tab[numerWygranego].infoCar(wszystko);
	cout << wszystko;
	return 0;
}