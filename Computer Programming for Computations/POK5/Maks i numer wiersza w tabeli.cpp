#include <iostream>
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

main()
{
	float tab[20][20],maks;
	int i,j,n,wiersz,licznik;
	printf("Program do szukania maks tab i ostatniej pozycji\n");
	printf("Podaj wymiar macierza kwadratowego : ");
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			{
				printf("Podaj element tablicy : ");
				scanf("%f", &tab[i][j]);
			}
	printf("Macierz\n");
	for(i=0; i<n; i++)
	{
		if(i==0)
			maks=tab[0][0];
		for(j=0; j<n; j++)
			{
				licznik = n;
				if(tab[i][j]>=maks)
				{
					maks=tab[i][j];
					licznik--;
				}
				printf("%0.0f ", tab[i][j]);
				if (licznik<n)
				wiersz = i+1;
			}
		printf("\n");
 	}
 	printf("Maks to : %0.0f\n", maks);
 	printf("Wiersz w ktorym jest maks : %d\n", wiersz);
			
			system("pause");
			return 0;
}
