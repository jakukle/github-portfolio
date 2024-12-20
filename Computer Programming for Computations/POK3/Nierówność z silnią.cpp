#include <iostream>
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>

main()
{
	float y,p=1, n, q, E,e=2.7,iloczyn=1,s;
	printf ("Program do obliczania pewnej nierownosci\n");
		printf ("Podaj n : ");
	scanf ("%f", &n);
		printf ("Podaj q : ");
	scanf ("%f", &q);
		printf ("Podaj E : ");
	scanf ("%f", &E);
	
	y = (1.0/iloczyn) * pow(n-q, p-1) * pow(e, n*q);
	printf("Wartosc y = %0.1f\n", y);
	do
	{
		p++;
		iloczyn = iloczyn * p;
		y = (1.0/iloczyn) * pow(n-q, p-1) * pow(e, n*q);
		if (y>E)
		{
		printf("Wartosc y = %0.1f\n", y);
		s=y;
	   }
		else printf("Wartosc koncowa y = %0.1f\n", s);

	} while (y>E);
	printf("Wartosc minimalna p to : %0.0f\n", p);
	
	system ("pause");
	return 0;
}
