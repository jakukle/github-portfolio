#include <iostream>
using namespace std;

class Ssak
{
public:
    Ssak()  {}
    ~Ssak() {}
    virtual void Mow() const
    {
        cout << "SSAK DAJE GLOS\n";
    }
};

class Pies : public Ssak
{
public:
    void Mow()const
    {
        cout << "PIES DAJE GLOS - HAU\n";
    }
};

void FunkcjaWartosc(Ssak);
void FunkcjaWskaznik(Ssak*);
void FunkcjaReferencja(Ssak&);

int main()
{
    Ssak* Wskaznik = 0;
    Wskaznik = new Pies;
    FunkcjaWartosc(*Wskaznik);
    FunkcjaWskaznik(Wskaznik);
    FunkcjaReferencja(*Wskaznik);
    return 0;
}
void FunkcjaWartosc(Ssak a)
{
    a.Mow();
}
void FunkcjaWskaznik(Ssak *a)
{
    a->Mow();
}
void FunkcjaReferencja(Ssak &a)
{
    a.Mow();
}

