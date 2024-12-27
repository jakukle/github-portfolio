#include <iostream>
using namespace std;
enum RASA { BULLTERIER, OWCZAREK, PITBULL, SHETLAND, DOBERMAN, LABRADOR };
class Ssak
{
public:
    //konstruktory
    Ssak();
    Ssak(int wiek);
    ~Ssak();
    //Funkcje dostepu
    int PobierzWiek() const
    {
        return nJegoWiek;
    }
    void UstawWiek(int wiek)
    {
        nJegoWiek = wiek;
    }
    int PobierzWaga() const
    {
        return nJegoWaga;
    }
    void UstawWaga(int waga)
    {
        nJegoWaga = waga;
    }
    //Inne metody
    void Mow() const
    {
        cout << "SSAK DAL GLOS\n";
    }
    void Spij() const
    {
        cout << "CICHO BO JA TERAZ SPIE\n";
    }
protected:
    int nJegoWiek;
    int nJegoWaga;
};

Ssak::Ssak() : nJegoWaga(5)
{
    nJegoWiek = 2;
    cout << "KONSTRUKTOR SSAKA\n";
}
Ssak::Ssak(int wiek) : nJegoWiek(wiek), nJegoWaga(6)
{
    cout << "KONSTRUKTOR SSAKA (int)\n";
}
Ssak::~Ssak()
{
    cout << "DESTRUKTOR SSAKA\n";
}

class Pies : public Ssak
{
public:
    //Konstruktory
    Pies();
    Pies(int wiek);
    Pies(int wiek, int waga);
    Pies(int wiek, RASA rasa);
    Pies(int wiek, int waga, RASA rasa);
    ~Pies();
    //Funkcje dostepu
    RASA PobierzRasa() const
    {
        return nJegoRasa;
    }
    void UstawRasa(RASA rasa)
    {
        nJegoRasa = rasa;
    }
    //Inne metody
    void MachajOgonem()
    {
        cout << "Macham sobie ogonkiem\n";
    }
    void ProsOJedzenie()
    {
        cout << "Daj jedzonko\n";
    }
private:
    RASA nJegoRasa;
};


Pies::Pies() : Ssak(), nJegoRasa(LABRADOR)
{
    cout << "KONSTRUKTOR PSA\n";
}
Pies::Pies(int wiek) : Ssak(wiek), nJegoRasa(LABRADOR)
{
    nJegoWiek = 1932;
    cout << "KONSTRUKTOR PSA (int)\n";
}
Pies::Pies(int wiek, int waga) : Ssak(wiek), nJegoRasa(LABRADOR)
{
    nJegoWaga = waga;
    cout << "KONSTRUKTOR PSA (int,int)\n";
}
Pies::Pies(int wiek, int waga, RASA rasa) : Ssak(wiek), nJegoRasa(rasa)
{
    nJegoWaga = waga;
    cout << "KONSTRUKTOR PSA(int,int,RASA)\n";
}
Pies::Pies(int wiek, RASA rasa) : Ssak(wiek), nJegoRasa(rasa)
{
    cout << "KONSTRUKTOR PSA (int,RASA)\n";
}
Pies::~Pies()
{
    cout << "DESTRUKTOR PSA\n";
}


int main()
{
    Pies Marcin;
    cout << "Marcin ma " << Marcin.PobierzWiek() << " lat\n";
    cout << "Marcin ma " << Marcin.PobierzWaga() << " kilo\n";
    Marcin.Mow();
    Pies Filip(31);
    cout << "Filip ma " << Filip.PobierzWiek() << " lat\n";
    cout << "Filip ma " << Filip.PobierzWaga() << " kilo\n";
    Filip.MachajOgonem();
    Pies Dawid(32, 33);
    cout << "Dawid ma " << Dawid.PobierzWiek() << " lat\n";
    cout << "Dawid ma " << Dawid.PobierzWaga() << " kilo\n";
    Pies Mateusz(34, BULLTERIER);
    cout << "Mateusz ma " << Mateusz.PobierzWiek() << " lat\n";
    cout << "Mateusz ma " << Mateusz.PobierzWaga() << " kilo\n";
    Pies Sebastian(35, 36, DOBERMAN);
    cout << "Sebastian ma " << Sebastian.PobierzWiek() << " lat\n";
    cout << "Sebastian ma " << Sebastian.PobierzWaga() << " kilo\n";
    return 0;
}
