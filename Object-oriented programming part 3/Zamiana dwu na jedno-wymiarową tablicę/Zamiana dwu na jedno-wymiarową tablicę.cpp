#include <iostream>
using namespace std;

int main()
{
    int nSize;
    int i, j;
    cout << "Podaj pierwszy wymiar: ";
    cin >> nSize;

    int(*Tab)[3] = new int[nSize][3];

    for (i = 0; i < nSize; ++i)
    {
        for (j = 0; i < 3; ++j)
        {
            Tab[i][j] = 10 * i + j;
        }
    }
    int* PTab = reinterpret_cast<int*>(Tab);
    for (i = 0; i < 3 * nSize; ++i)
    {
        cout << PTab[i] << " ";
    }

    cout << endl;

    cout << "Adres Tablica[0]:   " << Tab[0] << endl;
    cout << "Adres Tablica[1]:   " << Tab[0] << endl;
    cout << "sizeof(Tablica[0]):   " << sizeof(Tab[0]) << endl;
    return 0;
}


