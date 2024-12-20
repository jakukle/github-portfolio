#include <cstdlib>
#include <iostream>

void zamiana(int x)
{
	int i=0,k=0,tab[31];
	char tablica[31];
	while(x!=0) 
	{
		tab[i]=x%2;
		tablica[i]=x%2 +'0';
		i++;
		x/=2;
	}
	printf("To jest i %d\n", i);
	for(k=0; k<i; k++)
	{
		//if(tab[i]==0)
		//tablica[i] = (char)tab[i] + '0';
		//else tablica[i] = (char)tab[i] + '1';
	}

	for(int j=i-1;j>=0;j--)
		printf("%d", tab[j]);
	
	printf("\n");	

	for(int j=i-1;j>=0;j--)
		printf("%c", tablica[j]);
}

int main()
{
	int x;
	scanf("%d", &x);
	zamiana(x);
	printf("\n");
	system("pause");
	return 0;
}
