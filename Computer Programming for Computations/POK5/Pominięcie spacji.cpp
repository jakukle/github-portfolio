#include <iostream>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <time.h>

main()
{
	char napis[100], zamiana[100];
	int dl,i,l=0;
	printf("Program \n");
	gets(napis);
	dl = strlen(napis);
	printf("Dlugosc to : %d\n", dl);
	for(i=0; i<=dl; i++)
	{
		if(napis[i]==' ')
			l++;
		else 
		    zamiana[i-l] = napis[i];
	}
	
	printf("%s\n", zamiana);

	system("pause");
	return 0;
}
