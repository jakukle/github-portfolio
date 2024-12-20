#include <iostream>
#include <math.h>
#include <stdio.h>

main()
{
	float ai, ap, app, appp;
	int i, N, j=0;
	printf("Program obliczajacy N poczatkowych wyrazow ciagu\n");
	ai = ap*sqrt(app + appp);
	ap=1;
	app=1.5;
	appp=2;
	scanf("%d", &N);
	for(i=1; i<=N; i++)
		{
			j++;
			ai = ap * sqrt(app + appp);
			printf("%d wyraz ciagu rowna sie : %f \n", j, ai);
			appp = app;
			app = ap;
			ap = ai;	
		}
		system ("pause");
		return 0;
}
