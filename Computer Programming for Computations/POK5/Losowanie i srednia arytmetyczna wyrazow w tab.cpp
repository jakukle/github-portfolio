#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n,m,i,j;
	char c;
	srand(time(NULL));
	printf("podaj rozmiar tablicy NxM:\n");
	scanf("%d %d",&n,&m);
	float a[n][m],x;
	
	for(i=0;i<n;i++)
		{
		for(j=0;j<m;j++)
			{
			a[n][m]=0;
			};
		};
		
	for(j=0;j<m;j++)
		{
			i=0;
			a[i][j]= rand()%11;
		};
	
	for(i=1;i<n;i++)
		{
			j=0;
			a[i][j]= rand()%11;
		};
	
	for(j=1;j<m;j++)
		{
			for(i=1;i<n;i++)
			{
			x=(a[i-1][j]+a[i][j-1]);
			a[i][j]=x/2;
			};
		};
	
	for(i=0;i<n;i++)
		{
		for(j=0;j<m;j++)
			{
				printf("a[%d][%d]=%0.5f\t",i,j,a[i][j]);
			};
			printf("\n");
		};
	printf("\n\naby zakonczyc wcisnij cos\n");
	scanf("%c", &c);
	getchar();
	return 0;
}
