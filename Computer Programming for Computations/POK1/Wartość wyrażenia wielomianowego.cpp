#include <iostream>
#include <math.h>
#include <stdio.h>
main()
{
	printf("Program liczacy wartosc wyrazenia");
	float y,x,b,c;
	b=7.5;
	printf("\nPodaj c : ");
	scanf("%f", &c);
	printf(" y = 2x^4 + 7.5x^3 + %0.1fx^2 + 8", c); // %0.1f to precyzja ( czyli ile liczb po przecinku )
	printf("\nPodaj x : ");
	scanf("%f", &x);
	y = 2*pow(x,4) + b*pow(x,3) + c*pow(x,2) + 8;
	printf("%f", y);
	printf("\n");

/*	int g;
	int abs(int g);
	scanf("%d", &g);
	printf("%d", abs(g));
*/	
	
	return 0;
	
}
