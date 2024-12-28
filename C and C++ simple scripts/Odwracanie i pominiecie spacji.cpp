#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int dl, i, j=0;
	char tab[220], tab2[220];
	gets(tab);
	dl=strlen(tab);
	printf("%s\n", tab);
	for(i=0; i<=dl; i++)
		if(tab[dl-i-1] != ' ')
		{
			tab2[j]=tab[dl-i-1];
			j++;
		}
	
	for(i=0; i<j; i++)
		printf("%c", tab2[i]);
		printf("\n");
	system("pause");
	return 0;
}
