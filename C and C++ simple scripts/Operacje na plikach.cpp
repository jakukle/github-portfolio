#include <stdio.h>
#include <stdlib.h>

int main()
{
	char tekst[ ] = "Szymon Supczing";
	
	FILE *plik;
	plik = fopen("Aha.txt", "a");
	fprintf(plik,"%s",tekst);
	fclose(plik);
	
	return 0;
}
