#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
		int A,i,n;
		float x;
		srand(time(NULL));
		FILE *plik;
		plik=fopen("dane.txt","w");
		printf("podaj A i ilosc losowanych liczb:\n");
		scanf("%d %d", &A, &n);
		
		for(i=0;i<n;i++)
			{
				x=-A+2*A*rand()/(float)RAND_MAX;
				fprintf(plik, "%f\n", x);
				printf("%f\n", x);
			};
		fclose(plik);
		getchar();
		return 0;
}
