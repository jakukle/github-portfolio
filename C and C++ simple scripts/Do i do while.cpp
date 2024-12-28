#include <iostream>
#include <stdio.h>
#include <math.h>

main()
{
	printf("Petle\n\n");
	
	printf("------------------\n\n");
	
	printf("Suma w petli while\n");
	int a,suma=0;
	while ( suma <= 100)
		{
			printf ("Podaj liczbe : ");
			scanf("%d", &a);
			suma = suma + a;
			printf ("Aktulna suma wynosi : %d\n", suma);
		}
    printf("Suma przekroczyla 100\n");
    printf("Suma wynosi : %d\n\n", suma);
    suma = 0;
    
    //
    
    printf("Suma w petli do while\n");
    do
    {
    	printf ("Podaj liczbe : ");
    	scanf("%d", &a);
    	suma = suma + a;
    	printf ("Aktulna suma wynosi : %d\n", suma);
    }
    	while ( suma <= 100);
	
	printf("Suma przekroczyla 100\n");
    printf("Suma wynosi : %d\n\n", suma);
	
    
system ("pause");
return 0;
	
}
