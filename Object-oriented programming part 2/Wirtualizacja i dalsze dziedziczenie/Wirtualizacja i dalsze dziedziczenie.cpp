#include <iostream>
using namespace std;

class Ksztalt
{
public:
    Ksztalt() {}
    ~Ksztalt() {}
    virtual long PobierzPole() = 0;
    virtual long PobierzObwod() = 0;
    virtual void Rysuj() = 0;
private:
};
void Ksztalt::Rysuj()
{
    cout << "NIE MOGE CI NIC NARYSOWAC BO TO OGOLNY ABSTRAKCYJNY PRZEPIS DO KONKRETNYCH OBIEKTOW\n";
}

class Kolo : public Ksztalt
{
public:
    Kolo(int nPromien) : nJegoPromien(nPromien) {}
    ~Kolo() {}
    long PobierzPole() { return 3 * nJegoPromien * nJegoPromien; }
    long PobierzObwod() { return 6 * nJegoPromien; }
    void Rysuj();
private:
    int nJegoPromien;
};

void Kolo::Rysuj()
{
    cout << "\t0oO\n";
    Ksztalt::Rysuj();
}

class Prostokat : public Ksztalt
{
public:
    Prostokat(int nDlugosc, int nSzerokosc):
    nJegoDlugosc(nDlugosc), nJegoSzerokosc(nSzerokosc) {}
    ~Prostokat() {}
    long PobierzPole() { return nJegoDlugosc * nJegoSzerokosc; }
    long PobierzObwod() { return 2 * nJegoDlugosc + 2 * nJegoSzerokosc; }
    virtual int PobierzDlugosc() { return nJegoDlugosc; }
    virtual int PobierzSzerokosc() { return nJegoSzerokosc; }
    void Rysuj();
private:
    int nJegoSzerokosc;
    int nJegoDlugosc;
};
void Prostokat::Rysuj()
{
    for (int i = 0; i < nJegoDlugosc; i++)
    {
        for (int j = 0; j < nJegoSzerokosc; j++)
            cout << "O";
            cout << "\n";
    }
    Ksztalt::Rysuj();
}
class Kwadrat : public Prostokat
{
public:
    Kwadrat(int nDlugosc);
    Kwadrat(int nDlugosc, int nSzerokosc);
    ~Kwadrat() {}
    long PobierzObwod() { return 4 * PobierzDlugosc(); }
};

Kwadrat::Kwadrat(int nDlugosc);
Prostokat(nDlugosc, nDlugosc) {}

Kwadrat::Kwadrat(int nDlugosc, int nSzerokosc)
Prostokat(nDlugosc, nSzerokosc)
{
    if (PobierzDlugosc() != PobierzSzerokosc())
        cout << "Blad. To nie jest kwadrat\n";
}
int main()
{
    int nWybor;
    bool fKoniec = false;
    Ksztalt* sp;
    while (1)
    {
        cout << "1 to kolo, 2 to prostokat, 3 to kwadrat, inne to koniec: ";
        cin >> nWybor;
        switch (nWybor)
        {
        case 1: sp = new Kolo(4)
            break;
        case 2: sp = new Prostokat(8);
            break;
        case 3: sp = new Kwadrat(7);
            break;
        default fKoniec = true;
            break;
        }
        if (fKoniec)
            break;
        sp->Rysuj();
        cout << "\n";
    }
    return 0;
}
