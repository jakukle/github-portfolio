#include <stdio.h>

int main()
{
	int liczba;
	int i=0;
	
	printf("Podaj liczbe: ");
	scanf("%d", &liczba);
	printf("%d\n", i+1);
	printf("%d\n", liczba);
	
	while (i <= liczba)
	{
	    printf("%d\n", i);
		i = i+1;
		
	}
	
	return 0;
}
