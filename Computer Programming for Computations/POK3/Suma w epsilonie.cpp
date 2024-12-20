#include <iostream>
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>

main()
{
	float y, i, N, suma=0,x;
	printf ("Program do obliczania pewnej sumy\n");
	printf ("Podaj x : ");
	scanf ("%f", &x);
	printf ("Podaj N (wieksze od minus 5) : ");
	scanf ("%f", &N);
	for (i=-5; i<=N; i++)	
		{
			y = pow(x,i) * sin(i*x);
			suma = suma + y;
			}
		printf("suma = %f\n", suma);	
	system ("pause");
	return 0;
}
