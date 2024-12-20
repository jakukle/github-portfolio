#include <string.h>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>

main()
{
	float tab[10][10];
	int i,a,b,x,y,z;
	printf("Program sprawdzania macierzy kwadratowych\n");
	printf("Podaj wymiary macierza\n");
	printf("Podaj liczbe wierszy i kolumn : ");
	scanf("%d", &i);
	
	for(a=0; a<i; a++)	
		for(b=0; b<i; b++)
		{
			printf("Podaj element tablicy : ");
			scanf("%f", &tab[a][b]);
		}
		
	for(a=0; a<i; a++)
	{
		for(b=0; b<i; b++)
		{
			printf("%0.0f ", tab[a][b]);
		}
	printf("\n");
	}



	for(a=0; a<i; a++)
	{
			
		for(b=0; b<i; b++)
		{
			 if(tab[a][b]==tab[b][a])
				x=1;
			else 
		 		{
				x=0; 
			 	break;
			 	}
		if(x==0) break;		
	    }
	}
	if(x==1) printf("tablica jest symetryczna\n");
	
	
	
		for(a=0;a<i;a++) 
		{
			for(b=0;b<i;b++)
			{
			if(a!=b && tab[a][b]!=0) {y=0;break;}
			else y=1;
			}
		 if(y==0) break;
		}
	if(y==1) printf("tablica jest diagonalna\n");
	
	
		
	for(a=0;a<i;a++) 
	{
		for(b=0;b<i;b++)
			{
			if(a>b && tab[a][b]!=0) {z=0; break;}
			else z=1;
			}
		if(z==0) break;
	}
	if(z==1) printf("tablica jest gorno-trojkatna\n");

	system("pause");
	return 0;
}
