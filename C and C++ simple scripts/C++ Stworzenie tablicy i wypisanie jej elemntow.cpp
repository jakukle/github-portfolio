//Napisz program tworz¹cy tabl. jednowymiarow¹ i wypisuj¹cy elementy tej tabl.
#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
int n, tab[10];
   cout << "Podaj z ilu elementow ma skladac sie tablica " << endl;
    cin >> n;
   cout<<endl;
for (int i=0; i < n ; i++)
 {
   cout << "podaj wartosc elementu ";
    cin >> tab[i];
 }
   cout<<endl;
   cout << "Elementy tablicy " << endl;
for (int i=0; i < n ; i++)
 {
cout << tab[i] <<" ";
 }
    cout<<endl;
system ("PAUSE");
return EXIT_SUCCESS;
}
