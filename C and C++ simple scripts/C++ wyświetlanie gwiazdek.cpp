#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
int i;
cout << "program wyswietlajacy na ekranie zadana liczbe gwiazdek\n";
cout << "podaj liczbe liczbe gwiazdek do narysowania" << endl;
cin >> i;
do
{
 if (i<1)
 {
 cout << "gwiazdek nie moze byc wcale albo mniej od zera gluptasku";
 break;
}
 cout << "*";
 i--;
}
while (i);
cout<<endl;
system ("PAUSE");
return EXIT_SUCCESS;
}
