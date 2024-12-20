#include <iostream>
#include <math.h>

main()
{
	printf("Program obliczajacy wartosc wyrazenia");
	float z, x;
	printf("\nPodaj x : ");
	scanf("%f", &x);
	if (((3*x*x)-(7*x)+2)==0)
       printf("Mianownik jest rowny 0 - Nie mozna dzielic przez 0!");
	else {
	   z=(sqrt(x+2))/((3*x*x)-(7*x)+2);
	   printf("%f", z); }
return 0;
}
