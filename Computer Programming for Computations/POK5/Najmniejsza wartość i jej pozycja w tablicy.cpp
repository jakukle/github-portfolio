#include <iostream>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <time.h>

main()
{
	int tab[20], min,j=0,i,pozycja;
	printf("Najmniejsza wartosc i jej pozycja w tablicy\n");
	
	for(i=0; i<=19; i++)
	{
		
		printf("%d Podaj liczbe : ", i+1);
		scanf("%d", &tab[i]);
		if(j==0)
			min=tab[i];
		if(tab[i]<min)
			{
				min=tab[i];
				pozycja = i;
			}
		j++;
	}
	printf("Minimum to : %d\n", min);
	printf("Pozycja minimum to : %d\n", pozycja+1);
	system("pause");
	return 0;
}

