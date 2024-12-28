#include <iostream>
#include <math.h>
#include <stdio.h>

main()
{
	float n,x, xp, xpp, xppp, e=2.7,i;
	printf("Program obliczajacy dane wyrazenie\n");
	printf("Podaj nam xp : ");
	scanf("%f", &xp);
	printf("Podaj nam xpp : ");
	scanf("%f", &xpp);
	printf("Podaj nam xpp : ");
	scanf("%f", &xp);
	printf("Podaj nam n : ");
	scanf("%f", &n);
	
	x = pow(fabs(sin(xpp * xp)*pow(e,xppp)), 1.0/2.0);
	
	for(i=1; i<=n; i++)
		{
			x = pow(fabs(sin(xpp * xp)*pow(e,xppp)), 0.5);
			printf ("x to : %f\n", x);
			xppp=xpp;
			xpp=xp;
			xp=x;
		}
		printf ("=====\n");
		printf ("Ostateczny x to : %f\n", x);
	system("pause");
	return 0;
}
