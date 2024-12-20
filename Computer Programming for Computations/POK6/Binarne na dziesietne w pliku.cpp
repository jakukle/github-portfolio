#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    
    char liczba[256];
    int tab[2000];
    int suma,i,n;
    FILE *plik;
    FILE *zapis;
    
    plik=fopen("binarne.txt", "rt");
    zapis=fopen("dziesietne.txt", "wt");
    
    while(fscanf(plik, "%s", &liczba)==1)
    {
                       suma=0;
                       printf("liczba = %s \n", liczba);
                       n=strlen(liczba);
                       for(i=0; i<n; i++)
                       {
                                if(liczba[i]=='1')
                                tab[i]=1;
                                else
                                tab[i]=0;            
                       }
                       tab[i+1]=2;
                       for(i=0; n!=0 ; i++)
                       {
                                suma=suma+(tab[n-1]*pow(2,i));
                                n--;
                       }
                       fprintf(zapis, "%d\n", suma);                       
    }

    fclose(plik);
    return 0;
}
                       
