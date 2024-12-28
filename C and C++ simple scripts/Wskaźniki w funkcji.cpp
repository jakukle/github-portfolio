#include <iostream>
#include <math.h>
#include <stdio.h>
#include <cstdlib>

int funkcja (int tab[], int N, int *parzyste, int *nieparzyste, int *przez)
{
	int i=0;
	for(i=0; i<N; i++)
	{
	if(tab[i]%2==0)
		*parzyste=*parzyste+1;
	if(tab[i]%2==1)
		*nieparzyste=*nieparzyste+1;
   	if(tab[i]%4==0)
		*przez=*przez+1;
	}
}
int main()
{
	int x=0, y=0, z=0, N,i;
	printf("Podaj ile elementow : ");
	scanf("%d", &N);
	int tab[N];
		for(i=0;i<N;i++)
	{
		tab[i]=rand();
		printf("%d\n",tab[i]);
	}
	funkcja(tab, N, &x, &y, &z);
	printf("%d %d %d", x, y,z);
	return 0;
}
