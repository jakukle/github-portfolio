#include <stdlib.h>
#include <iostream>

/* za pomoc� operatora "*" informujemy kompilator o tym, �e argumentem funkcji b�dzie wska�nik. Wewn�trz funkcji te� musimy pami�ta�, �e warto�ci "a" i "b" to wska�niki, wi�c zn�w trzeba u�ywa� operatora "*" */
int Add(int *a, int *b)
{
int wynik=*a+*b;
*a=*b=0;
return wynik;
}

int main()
{
int x=1,y=2,z;

/*aby przekaza� do funkcji adres zmiennej trzeba u�y� operatora pobrania adresu "&"*/
z=Add(&x,&y);

printf("Wynik = %d\n", z);
printf("a = %d\n", x); /* wypisanie zmiennych kt�re wewn�trz*/
printf("b = %d\n", y); /* funkcji zosta�y wyzerowane*/
system("PAUSE");
return 0;
}
