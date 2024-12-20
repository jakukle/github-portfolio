#include <iostream>
#include <math.h>
#include <stdio.h>

main()
{
	float sumawszystkich=0, sumawiekszych0=0, sumamniejszych0=0, srednia=0, sredniamniejszych0=0, liczba;
	int n, i, licznik=0, zliczacz=0;
	printf("Programy liczacy kilka rzeczy ( na przyklad sume wczytanych liczb )\n");
	printf("Podaj ilosc liczb do wczytania : ");
	scanf("%d", &n);
	printf("Ilosc liczb to : %d\n", n);
if(n<=0)
	{
	   printf("Brak liczb - KONIEC PROGRAMU");
	   exit (0);
	}
else
   { 
	for (i=1; i<=n; i++)
	    {
	    	printf("Podaj liczbe : ");
	    	scanf("%f", &liczba);
	    	sumawszystkich = sumawszystkich + liczba;
	        	if(liczba>0)
	        	    zliczacz++;
	        		sumawiekszych0 = sumawiekszych0 + liczba;
	        srednia = sumawszystkich / i;
	        	if(liczba<0)
	        	    {
	        	    licznik++;
	        	    sumamniejszych0 = sumamniejszych0 + liczba;
	        		sredniamniejszych0 = sumamniejszych0 / licznik;
				    }
	    }
	    printf("Suma wszystkich liczb to : %f\n", sumawszystkich);
	        if(zliczacz>0)
	    printf("Suma liczb wiekszych od 0 to : %f\n", sumawiekszych0);
	    printf("Srednia wszystkich liczb to : %f\n", srednia);
	    	if(licznik>0)
	    printf("Srednia mniejszych od 0 to : %f\n", sredniamniejszych0);
   } 
   system("pause");
   return 0;
}
