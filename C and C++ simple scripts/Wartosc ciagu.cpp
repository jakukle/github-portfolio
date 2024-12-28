#include <iostream>
#include <stdio.h>
#include <math.h>
#include <conio.h>

main()
{
	float  x, xp,xpp; // po prostu e
	int i,n;
	scanf("%f %f %d", &xp, &xpp, &i);
	//printf("1\n");
    //x = (exp(xp) + fabs(xpp-4)) / sqrt(sin(xpp*xp));
    //printf ("%f", x);
	for(n=3; n<=i; n++)
	{
		// mozna x = (exp(xp)...
		x = (exp(xp) + fabs(xpp-4)) / sqrt(sin(xpp*xp));
		if (sin(xpp*xp) <= 0.0)
		{
			printf("1\n");
		}
		xpp = xp;
		xp = x;
		printf ("%f\n", x);
	}
	printf ("KONIEC TO %f\n", x);
	
	system("pause");
	return 0;
}
