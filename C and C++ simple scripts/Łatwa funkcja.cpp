#include <iostream>
#include <stdlib.h>

int Add(int a, int b)
{
int wynik=a+b;
a=b=0; /*wartoœci zmiennych wewn¹trz funkcji s¹ zerowane*/
return wynik;
}

int main()
{
int x=1,y=2,z;
z=Add(x,y);
printf("Wynik = %d\n", z);
printf("a = %d\n", x); /* wypisanie zmiennych które wewn¹trz*/
printf("b = %d\n", y); /* funkcji zosta³y "wyzerowane"*/
system("PAUSE");
return 0;
}

