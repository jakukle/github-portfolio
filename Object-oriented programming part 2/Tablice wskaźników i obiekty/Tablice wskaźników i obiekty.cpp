#include <iostream>
using namespace std;
class KOT
{
public:
    KOT()
    {
        nJegoWiek = 1;
        nJegoWaga = 5;
    }
    ~KOT()
    {}
    int PobierzWiek() const
    {
        return nJegoWiek;
    }
    void UstawWiek(int nWiek)
    {
        nJegoWiek = nWiek;
    }
private:
    int nJegoWiek;
    int nJegoWaga;
};


int main()
{
    KOT* Dynastia[500];
    KOT* poKot;
    for (int i = 0; i < 500; i++)
    {
        poKot = new KOT;
        poKot->UstawWiek(2 * i + 1);
        Dynastia[i] = poKot;
    }
    for (int i = 0; i < 500; i++)
    {
        cout << "KOT " << (i + 1) << ": " << Dynastia[i]->PobierzWiek() << endl;
    }
    return 0;
}
