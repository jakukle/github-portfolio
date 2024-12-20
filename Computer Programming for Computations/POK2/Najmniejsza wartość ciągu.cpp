#include <iostream>
#include <math.h>
#include <stdio.h>

main()
{
	int Np, Nk, ai, i, suma=0, najmn;
	printf("Program do ciagow\n");
	printf("Podaj Np : ");
	scanf("%d", &Np);
	printf("Podaj Nk (musi byc wieksze od Np) : ");
	scanf("%d", &Nk);
	najmn = -Np*Np + 15*Np + 50;
	for (i=Np; i<=Nk; i++)
	{
		ai = -i*i + 15*i + 50;
		suma = suma + ai;
		if (ai < najmn)
		najmn = ai;		
	}
printf("Suma ciagu to : %d\n", suma);
printf("Najmniejsza wartosc wyrazu : %d\n", najmn);

system("pause");
return 0;	
}
