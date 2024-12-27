#include "Car.h"

using namespace std;


Car::Car():
	numerStartowy(0),
	paliwoWBaku(0.0),
	przebieg(0.0)
{
	srednieSpalanie = (double)rand() / RAND_MAX * (0.06) + 0.04;
	pojemnoscBaku = (double)rand() / RAND_MAX * (60) + 40;
}

bool Car::przejedzDystans(double dystans)
{
	double przejechanyDystans = dystans * srednieSpalanie;
	if (przejechanyDystans <= paliwoWBaku)
	{
		przebieg += dystans;
		paliwoWBaku -= (dystans * srednieSpalanie);
		return true;
	}
	else
	{
		double ileDalRady = paliwoWBaku / srednieSpalanie;
		paliwoWBaku = 0.0;
		przebieg += ileDalRady;
		return false;
	}
		
}

void Car::tankowanie(double zmianaPaliwa)
{
	if (zmianaPaliwa + paliwoWBaku > pojemnoscBaku)
		paliwoWBaku = pojemnoscBaku;
	if (zmianaPaliwa + paliwoWBaku < 0.0)
		paliwoWBaku = 0.0;
	if ((zmianaPaliwa + paliwoWBaku >= 0.0) && (zmianaPaliwa + paliwoWBaku <= pojemnoscBaku))
		paliwoWBaku += zmianaPaliwa;
}

void Car::nadanieNumeru(unsigned int numer)
{
	numerStartowy = numer;
}

double Car::pobierzPrzebieg()const
{
	return przebieg;
}

double Car::pobierzPaliwo()const
{
	return paliwoWBaku;
}

double Car::pobierzPojemnosc()const
{
	return pojemnoscBaku;
}

void Car::infoCar(string &info)
{
	info = "Numer startowy: " + to_string(numerStartowy) + "\n" +
		"Spalanie: " + to_string(srednieSpalanie) + "\n" +
		"Przebieg: " + to_string(przebieg) + "\n" +
		"Pojemnosc baku: " + to_string(pojemnoscBaku) + "\n" +
		"Stan paliwa: " + to_string(paliwoWBaku) + "\n";
}


