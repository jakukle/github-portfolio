#include <iostream>
#include <math.h>
#include <stdio.h>
#include <conio.h>

main()
{
	float x, y, e, suma=0, i,n; 
	int j=0;
	printf("Program funckji matematycznej\n");
	printf("Podaj x ( |x| < 1 ) : ");
	scanf("%f", &x);
	printf("Podaj n : ");
	scanf("%f", &i);
	printf("Podaj e : ");
	scanf("%f", &e);
	
	for (n=0; n<=i; n++)
	{
			
			y = (pow(-1,n)*pow(x,n+1))/(n+1);
			printf("Wartosc %d y = %f\n",j, y);
			j++;
			suma = suma + y;
			printf("Suma wynosi %f\n", suma);
			if (fabs(y)<e)
				{
					printf("y = %f\n", y);
					printf("Koncowa Suma wynosi %f\n", suma);
					break;
				}
	}
	
	system("pause");
	return 0;
}
