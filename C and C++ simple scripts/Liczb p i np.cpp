#include <conio.h>
#include <stdio.h>
int a;
int main()
{
	printf("Podaj liczbe : \n");
	scanf("%d", &a);
	if(a%2==0)
	printf("Liczba parzysta");
	else printf("Liczba nieparzysta"); 
	return 0;
}
