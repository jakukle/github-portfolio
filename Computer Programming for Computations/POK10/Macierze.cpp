#include <cstdlib>
#include <iostream>
#include <stdio.h>

/*void funckja(int )
{
	int i=0,tab[31];

	while(x!=0) 
	{
		tab[i++]=x%2;
		x/=2;
	}

	for(int j=i-1;j>=0;j--)
		printf("%d", tab[j]);
}
*/
int main()
{
	int tab[50][50], tablica[50][50], a,b,x,y,i,j,k,l;
	
	
	printf("Podaj rozmiary tablicy A : ");
	scanf("%d %d", &a,&b);
	printf("Mam rozmiar\n");
	for(i=0; i<a; i++)
		for(j=0; j<b; j++)
		{
		printf("Podaj element tablicy A\n");
		scanf("%d", &tab[i][j]);
	}
	
	printf("Podaj rozmiary tablicy B : ");
	scanf("%d %d", &x,&y);
	printf("Mam rozmiar\n");
	for(k=0; k<x; k++)
		for(l=0; l<y; l++)
		{
		printf("Podaj element tablicy B\n");
		scanf("%d", &tablica[k][l]);
	}
	printf("\n");
    printf("Macierz A wyglada tak\n");
	for(i=0; i<a; i++)
	{
		for(j=0; j<b; j++)
		printf("%d ", tab[i][j]);
	printf("\n");
}

	 printf("Macierz B wyglada tak\n");
	for(k=0; k<x; k++)
	{
		for(l=0; l<y; l++)
		printf("%d ", tablica[k][l]);
	printf("\n");
}
	if(a==y)
	//	funkcja();
	
	printf("\n");
	system("pause");
	return 0;
}
