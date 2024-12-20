#include <iostream>
#include <math.h>

main()
{
	printf("Miejsca zerowe funckji liniowej");
	float x,a,b;
	printf("\nPodaj a i b : ");
	scanf("%f", &a);
	if (a==0) {
		printf("a=0 wiec funkcja jest stala");
		printf("\nmiejsce zerowe bedzie tylko wtedy gdy b=0 ale to nie jest juz funkcja liniowa tylko stala");
    }
	else {
	scanf("\n%f", &b); 
	x=-b/a;
	printf("miejsce zerowe tej funckji to : ");
	printf("%f",x);
	}
	
}
