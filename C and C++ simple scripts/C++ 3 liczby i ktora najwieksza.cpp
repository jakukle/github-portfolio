#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
int a,b,c;
cout << " program wypisujacy na ekranie najwieksza z trzech podanych liczb a,b,c \n";
cout << "podaj liczbe a ";
cin >> a;
cout << "podaj liczbe b ";
cin >> b;
cout << "podaj liczbe c ";
cin >> c;
if (a>b)
if (a>c)
cout << " najwieksza z podanych liczb to a = " << a;
 else
cout << " hahanajwieksza z podanych liczb to c = " << c;
else
if (b>c)
cout << " najwieksza z podanych liczb to b = " << b;
else
cout << " najwieksza z podanych liczb to c = " << c;
cout << "\n";
system ("PAUSE");
return EXIT_SUCCESS;
}
