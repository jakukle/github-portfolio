#include <iostream>
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>

main()
{
	float y, L, y0, Yin, Yi, E,i=0;
	printf ("Program do szukania granicy w uproszczeniu\n");
	printf("Podaj L : ");
	scanf("%f", &L);
	y=sqrt(L);
	printf("Pierwiastek z L to %0.9f", y);
	y0=L/2;
	Yi = y0;
	printf("\nPodaj do jakiej roznicy chczesz dazyc : ");
	scanf("%f", &E);
	Yin=(0.5)*(Yi + L/Yi);
	while (fabs(Yin - Yi) >= E)
	{
		i++;
		printf("OBEJSCIE PETLI NUMER : %0.0f\n", i);
		printf("Wartosc wyrazu to : %0.9f\n", Yin);
		printf("Roznica wynosi aktualnie : %0.9f\n", fabs(Yin - Yi));
		Yi = Yin;
		Yin=(1.0/2.0)*(Yi + (L/Yi));
			} 
		printf("Wartosc wyrazu to : %0.9f\n", Yin);
		printf("Roznica wynosi aktualnie : %0.9f\n", fabs(Yin - Yi));
		printf("Roznica osiagnela poziom : %0.9f\n", fabs(Yin - Yi));

	system ("pause");
	return 0;
}
