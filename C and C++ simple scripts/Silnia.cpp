#include <stdio.h>

int main()
{
   int liczba;
   long silnia;
	printf("Podaj liczbe : ");
	scanf("%d", &liczba);
	printf("Podana liczba to : %d\n",liczba);
   for(int i=liczba; i>=1; i--)
   {
   	long silnia;
   	silnia = silnia * i;
   	//printf("%d\n", i);
   	printf("%d\n", silnia);
   }
		printf("%d\n", silnia);    	
   return 0;
}
