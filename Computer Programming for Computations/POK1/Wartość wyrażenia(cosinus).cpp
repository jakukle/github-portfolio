#include <iostream>
#include <math.h>

main()
{
	printf("Program oblicza dane funkcje");
	double y,x,e;
	e=2.71828; 
	double cos (double x);
	printf("\nPodaj x : ");
	scanf("%lf", &x);
	if ((x>=1) && (x<=7))
	{
	   y=pow(2*x+0.25,0.25);
	   printf("%lf", y);
    }
	else 
	{
	y= cos(pow(e, 2*x));
    printf("%lf", y);
    } 
	return 0; 
	
}
