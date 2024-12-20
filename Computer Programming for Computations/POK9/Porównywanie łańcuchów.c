#include <stdio.h>
#include <string.h>

int funkcja( char L[255], char L1[255])
{
    int n=strlen(L);
    int k=strlen(L1);
    int ilosc=0,i,j=0;
    for(i=0; i<n; i++)
    {
             if(L[i]==L1[j])
             {
                           j++;
             }
             else
             {
                 j=0;
             }
             if(j==k)
             {
                        ilosc++;
                        j=0;
             }
    }
    return ilosc;
}

int main()
{
    char string[255];
    char szukany[255];
    printf("Podaj lancuch L: ");
    gets(string);
    printf("Podaj lancuch L1: ");
    gets(szukany);
    
    int wynik=funkcja(string, szukany);
    
    printf("Ilosc wyrazow to: %d \n", wynik);
    system("pause");
    return 0;
}
