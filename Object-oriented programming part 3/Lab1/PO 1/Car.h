#include <string>
using namespace std;
class Car
{
public:
	Car();
	bool przejedzDystans(double dystans);
	void tankowanie(double zmianaPaliwa);
	void nadanieNumeru(unsigned int numer);
	double pobierzPrzebieg()const;
	double pobierzPaliwo()const;
	double pobierzPojemnosc()const;
	void infoCar(string &info);

private:
	unsigned int numerStartowy;
	double paliwoWBaku;
	double pojemnoscBaku;
	double srednieSpalanie;
	double przebieg;
};

