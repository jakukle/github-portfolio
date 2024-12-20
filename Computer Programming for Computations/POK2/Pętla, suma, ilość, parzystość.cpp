#include <iostream>
#include <math.h>
#include <stdio.h>

main()
{   
    float sumawiekszych0=0, sredniawiekszych0=0, iloczynnieod5do10=1; 
    int liczba, i=0, j=0, zliczacz=0, licznik=0;
	printf("Program wczytujacy liczby do mniejszej od 0 z wieloma funkcjami\n");
	for (i=0; liczba>=0; i++)
		{
			printf("Podaj liczbe : ");
			scanf("%d", &liczba);
			if ( liczba>0 )
				{
			    	j++;
			    	sumawiekszych0 = sumawiekszych0 + liczba;
					sredniawiekszych0 = sumawiekszych0 / j;	
			    }
			if ( ((liczba < 5) || (liczba > 10))	&&	(liczba >= 0) )
				{
					licznik++;
					iloczynnieod5do10 = iloczynnieod5do10 * liczba;	
				}
			if ( liczba%2==0 )
					zliczacz++;	
			if ( liczba<0 && liczba%2==0)
			        zliczacz--;
		}
 	if (j>0)
	printf("Srednia liczb wiekszych od 0 to : %f\n", sredniawiekszych0);
	if (licznik>0)
	printf("Iloczyn liczb nienalezacych do przedzialu [5,10] to : %f\n", iloczynnieod5do10);
	if (zliczacz>0)
	printf("Ilosc liczb parzystych to : %d\n", zliczacz);
	
system ("pause");
return 0;
}
