#include <iostream>
#include <math.h>
#include <stdio.h>
#include <conio.h>

main()
{
	double y,x;
	printf("Program obliczajacy wartosc ulamka\n");
	printf("Podaj x : ");
	scanf("%lf", &x);
	if (sin(x)==0)
	{	
	   printf("Dzielenie przez 0\n");
	   exit(0);
    }
	else
	y = (pow(x*x+(1.0/3),(0.2)))/(fabs(sin(x)));
	 
	printf("%lf\n", y);
	
	system("pause");
	return 0;
	
}
