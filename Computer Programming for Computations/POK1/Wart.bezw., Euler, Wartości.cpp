#include <iostream>
#include <math.h>
#include <stdlib.h>

main()
{
	printf("Program obliczajacy wartosc wyrazenia\n");
	double exp (double x);
	double sin (double x);
	int abs (int x);
	double x,y;
	    printf("Podaj a : ");
		int a;
		scanf("%d", &a);
		printf("Wartosc bezwgledna a to %d\n", abs(a));
	printf("Podaj x : ");	
	scanf("%lf", &x);
	printf("Liczba Eulera %lf", exp(x));
	if (x<=-5)
	   y=2*x+10.0/3;
	else if(x>-5 && x<7)
	   y=sqrt(abs(x)) + exp(x/2+1);
	else 
	   y=pow((sin(2*x)+(pow(x,2))), (1.0/3));  
	printf("\nWartosc wyrazenia dla podanego x rowna sie %lf", y);    
	return 0;
} //abs(x) chyba dziala tylko na int bo faktycznie wynik
// jest zblizony ale nie dokladny
 
 

