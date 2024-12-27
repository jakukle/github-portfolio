#include <iostream>
using namespace std;

double** allocMatrix2D(int, int);
void deleteMatrix2D(double**&);

int main(void)
{
    int i, j, nDim1 = 2, nDim2 = 3;
    
    //alokowanie
    double** macierz2d = allocMatrix2D(nDim1, nDim2);

    //wpisywanie wartości
    for (i = 0; i < nDim1; i++)
    {
        for (j = 0; j < nDim2; j++)
        {
            macierz2d[i][j] = 3 * i + j + 1.5;
        }
    }
    //drukowanie
    for (i = 0; i < nDim1; i++)
    {
        for (j = 0; j < nDim2; j++)
        {
            cout << "Macierz2d[" << i << "][" << j << "] = " << macierz2d[i][j] << " ";
        }
        cout << endl;
    }
    //usuwanie
    deleteMatrix2D(macierz2d);
    return 0;
}

double** allocMatrix2D(int nDim1, int nDim2)
{
    double** macierz2d = new double* [nDim1];
    double* pDumm = new double[nDim1 * nDim2];

    for (int i = 0; i < nDim1; i++)
    {
        macierz2d[i] = pDumm + i * nDim2;
    }
    return macierz2d;
}

void deleteMatrix2D(double**& macierz2d)
{
    delete[] macierz2d[0];
    delete[] macierz2d;
    macierz2d = 0;
}
