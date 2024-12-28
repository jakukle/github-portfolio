
#include <stdio.h> 


int main()
{
	int suma=0;
	char a;
	int x;
	do{
	printf("podaj liczbe\n");
	scanf("%c",&a);
	getchar();
	x=(int)a;
	if (x!=84)
	{
	
		suma=suma+x-48;
	}
	}while(x!=84);
	printf("suma %d\n",suma);
	 return 0;
	
}
