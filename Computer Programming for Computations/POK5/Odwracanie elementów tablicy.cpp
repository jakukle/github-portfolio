#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <math.h>

main()
{
	float tab[30];
	int i,x,n;
	printf("Program odwracajacy kolejnosc liczb tablicy\n\n");
	printf("Podaj ilosc elementow tablicy : ");
	scanf("%d", &x);
	printf("\n");
	for(i=0; i<x; i++)
		{
			printf("Podaj wartosc elementu tablicy : ");
			scanf("%f", &tab[i]);
		}
	for(i=0; i<x/2; i++)
		{
			n=tab[x-1-i];
			tab[x-1-i]=tab[i];
			tab[i]=n;
		}
	for(i=0; i<x; i++)		
			printf("Tablica odwrocona %0.0f\n", tab[i]);
				
	system("pause");
	return 0;
}

