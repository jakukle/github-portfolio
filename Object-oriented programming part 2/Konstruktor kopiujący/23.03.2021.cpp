#include <iostream>
using namespace std;

class KOT
{
public :
	KOT();
	KOT(const KOT&);
	~KOT();
	int PobierzWiek() const
	{
		return *nJegoWiek;
	}
	int PobierzWaga() const
	{
		return *nJegoWaga;
	}
	void UstawWiek(int nWiek)
	{
		*nJegoWiek = nWiek;
	}
private:
	int *nJegoWiek;
	int *nJegoWaga;

};

KOT::KOT()
{
	nJegoWiek = new int;
	nJegoWaga = new int;
	*nJegoWiek = 5;
	*nJegoWaga = 9;
}
KOT::KOT(const KOT &rhs)
{
	nJegoWiek = new int;
	nJegoWaga = new int;
	*nJegoWiek = rhs.PobierzWiek();
	*nJegoWaga = rhs.PobierzWaga();
}
KOT::~KOT()
{
	delete nJegoWiek;
	nJegoWiek = 0;
	delete nJegoWaga;
	nJegoWaga = 0;
}
int main()
{
	KOT oFilemon;
	cout << oFilemon.PobierzWiek() << endl;
	oFilemon.UstawWiek(134);
	KOT oPikus(oFilemon);
	cout << oFilemon.PobierzWiek() << endl;
	cout << oPikus.PobierzWiek() << endl;
	oFilemon.UstawWiek(23);
	cout << oFilemon.PobierzWiek() << endl;
	cout << oPikus.PobierzWiek() << endl;
	oPikus.UstawWiek(600);
	cout << oFilemon.PobierzWiek() << endl;
	cout << oPikus.PobierzWiek() << endl;
}