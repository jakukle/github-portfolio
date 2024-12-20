#include <iostream>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

main()
{
	srand(time(NULL));
	int liczba, tab[11],i,j=1;
	printf ("Program losujacy 1000 liczb i okreslenie wystapien kazdej z nich\n");
	for(i=0; i<=10; i++)
	tab[i]=0; 
	// to tylko zerowanie zeby smieci nie bylo
	
		for(i=0; i<1000; i++)
			{
		liczba = rand() % 11;
		printf("%d liczba to %d\n", j,liczba+10);
		tab[liczba]++;
		j++;
    		}

 for(i=10; i<21; i++)
    {
             printf("Ilosc liczb %d = %d \n", i, tab[i-10]);
    }  
	system ("pause");
	return 0;

}




