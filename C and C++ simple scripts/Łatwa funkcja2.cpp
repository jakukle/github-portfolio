#include <stdlib.h>
#include <iostream>

/* za pomoc¹ operatora "*" informujemy kompilator o tym, ¿e argumentem funkcji bêdzie wskaŸnik. Wewn¹trz funkcji te¿ musimy pamiêtaæ, ¿e wartoœci "a" i "b" to wskaŸniki, wiêc znów trzeba u¿ywaæ operatora "*" */
int Add(int *a, int *b)
{
int wynik=*a+*b;
*a=*b=0;
return wynik;
}

int main()
{
int x=1,y=2,z;

/*aby przekazaæ do funkcji adres zmiennej trzeba u¿yæ operatora pobrania adresu "&"*/
z=Add(&x,&y);

printf("Wynik = %d\n", z);
printf("a = %d\n", x); /* wypisanie zmiennych które wewn¹trz*/
printf("b = %d\n", y); /* funkcji zosta³y wyzerowane*/
system("PAUSE");
return 0;
}
