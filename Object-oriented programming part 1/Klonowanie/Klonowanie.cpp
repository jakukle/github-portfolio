#include <iostream>
using namespace std;

class Ssak
{
public:
    Ssak(): nJegoWiek(1) 
    {
        cout << "KONSTRUKTOR SSAKA\n";
    }
    ~Ssak()
    {
        cout << "DESTRUKTOR SSAKA\n";
    }
    Ssak(const Ssak &rhs);
    virtual void Mow() const
    {
        cout << "GLOS SSAKA\n";
    }
    virtual Ssak *Klonuj()
    {
        return new Ssak(*this);
    }
    int GetWiek()const
    {
        return nJegoWiek;
    }
protected:
    int nJegoWiek;
};

Ssak::Ssak(const Ssak& rhs) : nJegoWiek(rhs.GetWiek())
{
    cout << "KONSTRUKTOR KOPIUJACY SSAKA\n";
}

class Pies : public Ssak
{
public:
    Pies()
    {
        cout << "KONSTRUKTOR PSA\n";
    }
    ~Pies()
    {
        cout << "DESTRUKTOR PSA\n";
    }
    Pies(const Pies& rhs);
    void Mow()const
    {
        cout << "SZCZEKAM SOBIE\n";
    }
    virtual Ssak* Klonuj()
    {
        return new Pies(*this);
    }
};

Pies::Pies(const Pies& rhs):

Ssak(rhs)
{
    cout << "KONSTRUKTOR KOPIUJACY PSA\n";
}

class Kot : public Ssak
{
public:
    Kot()
    {
        cout << "KONSTRUKTOR KOTA\n";
    }
    ~Kot()
    {
        cout << "DESTRUKTOR KOTA\n";
    }
    Kot(const Kot&);
    void Mow()const
    {
        cout << "MIALCZE SOBIE\n";
    }
    virtual Ssak* Klonuj()
    {
        return new Kot(*this);
    }
};

Kot::Kot(const Kot& rhs):

Ssak(rhs)
{
    cout << "KONSTRUKTOR KOPIUJACY KOTA\n";
}

enum ANIMALS {SSAK, PIES, KOT};
const int LiczbaTypowZwierzat = 3;

int main()
{
    Ssak *TablicaJeden[LiczbaTypowZwierzat];
    Ssak *wsk;
    int choice, i;
    for (i = 0; i < LiczbaTypowZwierzat; i++)
    {
        cout << "1 to pies, 2 to kot, 3 to po prostu ssak: ";
        cin >> choice;
        switch (choice)
        {
        case PIES: wsk = new Pies;
            break;
        case KOT: wsk = new Kot;
            break;
        default: wsk = new Ssak;
            break;
        }
        TablicaJeden[i] = wsk;
    }
    Ssak *TablicaDwa[LiczbaTypowZwierzat];
    for (i = 0; i < LiczbaTypowZwierzat; i++)
    {
        TablicaJeden[i]->Mow();
        TablicaDwa[i] = TablicaJeden[i]->Klonuj();
    }
    for (i = 0; i < LiczbaTypowZwierzat; i++)
        TablicaDwa[i]->Mow();
    return 0;
}

