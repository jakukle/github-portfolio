#include <iostream>
#include <math.h>
#include <stdio.h>
#include <conio.h>

main()
{
	float x,iloczyn=1,maks;
	int ilosc=1;
	printf("Program do kilku rzeczy z wypisywanie liczb\n");
	    printf("Podaj pierwszego x : ");
		scanf("%f", &x);
		iloczyn = iloczyn * x;
		maks = x;
	while (fmod(x,5)!=3)
	{ 
		printf("Podaj kolejnego x : ");
		scanf("%f", &x);
		if (x>maks)
			maks=x;
		ilosc++;
		iloczyn = iloczyn * x;
	}
 	printf("Ilosc liczb to : %d\n", ilosc);
	printf("Iloczyn liczb to : %0.3f\n", iloczyn);
	printf("Maks to : %0.3f\n", maks);
	
	system("pause");
	return 0;
}
