#include <iostream>
#include <math.h>
#include <stdio.h>

main()
{
	double a,b,delta,y,x,s,maks,srednia,suma,i;
	printf("Program do funckji i wartosci\n");
	printf("Podaj poczatek przedzialu czyli a : ");
	scanf("%lf", &a);
	printf ("Podaj koniec przedzialu czyli b : ");
	scanf ("%lf", &b);
	printf ("Podaj delte : ");
	scanf ("%lf", &delta);
	printf("\n");
	srednia = 0;
	suma=0;
	i = 0;
	for (x=a; x<=b; x=x+delta)
	{
		i++;
		s = sin(pow(x,0.5));
		printf("Dany x do obliczenia to : %lf\n", x);
	if(x<0)
		y = (x*x*x) + (1.0/x);
	if(x==0.0)
		y = 3 * pow(2,0.5);
	if(x>0)
		{
		if (s>=0)
			y = pow(sin(pow(x,0.5)), 1.0/3);
	    else
			{ 
	    		s = s*(-1);
	    		y = pow(s, 1.0/3);
	    		y = y*(-1);
			}
		}
		if(i==1)
		   maks = y;
		printf("Wartosc y dla danego x = %lf\n\n", y);
		suma = suma + y;
		srednia = suma / i;
		if (y>maks)
		maks = y;
}

    printf("Srednia rowna sie : %lf\n", srednia);
	printf("Maksymalna wartosc rowna sie : %lf\n", maks);
	
	system("pause");
	return 0;
}
