#include <string.h>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>

main()
{
	float tab[10][10],x;
	int i,a,b;
	printf("Program dokonujacy transpozycji macierzy\n");
	printf("Podaj wymiary macierza\n");
	printf("Podaj liczbe wierszy i kolumn : ");
	scanf("%d", &i);
	
	for(a=0; a<i; a++)	
		for(b=0; b<i; b++)
		{
			printf("Podaj element tablicy : ");
			scanf("%f", &tab[a][b]);
		}
		
	printf("Macierz\n");
		
	for(a=0; a<i; a++)
	{
		for(b=0; b<i; b++)
		{
			printf("%0.0f ", tab[a][b]);
		}
	printf("\n");
	}
	
	printf("Macierz transponowana bez tablicy\n");
	
	for(a=0; a<i; a++)
	{
		for(b=0; b<i; b++)
		{
			printf("%0.0f ", tab[b][a]);
		}
	printf("\n");
	}
	
	printf("Macierz transponowana z tablica\n");
	
	for(a=0; a<i; a++)
	{
		for(b=0; b<i; b++)
		{
			if(b>a)
			{
		    x = tab[b][a];
			tab[b][a] = tab[a][b];
			tab[a][b] = x;
	        }
 			printf("%0.0f ", tab[a][b]);
		}
	printf("\n");
	}
 
	
	system("pause");
	return 0;
}

