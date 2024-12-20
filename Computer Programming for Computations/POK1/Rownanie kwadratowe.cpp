#include <iostream>
#include <math.h>

main()
{
	printf("Program sprawdzajacy i obliczajacy miejsca zerowe rownania kwadratowego");
	float y,x,a,b,c, delta, mz0, mz1, mz2;
	printf("\nPodaj a : ");
	 scanf("%f", &a);
		printf("Podaj b : ");
		 scanf("%f", &b);
			printf("Podaj c : ");
			 scanf("%f", &c);
	delta = b*b - (4*a*c);
	printf("delta rowna sie %f ", delta);
	if (delta==0)
	{
		mz0 = -b/(2*a);
		printf("\nmiejsce zerowe rowna sie %f", mz0);
    }
    else if (delta > 0)
    {
    	mz1 = (-b-sqrt(delta))/2*a;
    	mz2 = (-b+sqrt(delta))/2*a;
    	printf("\n1 miejsce zerowe rowna sie %f a drugie rowna sie %f", mz1,mz2);
	}
	else printf("\nDelta mniejsza od 0 - brak rozwiazan");
	
	printf("\nPodaj x : ");
	scanf("%f", &x);
	y=(a*x*x)+(b*x)+c;
	printf("Dla funkcji o takich podanych wspolczynnikach i takiego x wartosc rowna sie %f", y);
	  
	
	return 0;
}
