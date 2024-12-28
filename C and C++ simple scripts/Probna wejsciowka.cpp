#include <iostream>
#include <math.h>
#include <conio.h>
#include <stdio.h>

main()
{
	float suma = 0.0,x,wyrazenie,iloczyn=1.0,p,k,n2;
	printf("Podaj n2: ");
	scanf("%f", &n2);
	printf("Podaj x: ");
	scanf("%f", &x);
	
	for(p=1; p<=10; p++)
		{
			iloczyn=1.0;
			for(k=1;k<=p+n2; k++)
			{
				wyrazenie = cos(k*(2+p-x));
				iloczyn = iloczyn * wyrazenie;
			}
			suma = suma + iloczyn;
		}
	printf("suma = %f\n", suma);
	
	system("pause");
	return 0;
}
