#include <stdio.h>
#include <string.h>
#include <iostream>

int funkcja( char L[255], char L1[255])
{
    int n=strlen(L);
    int i,j=0;
    for(i=0; i<n; i++)
    {
             if(L[i]==L1[i])
                           j++;
            
    }
    return j;
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
    
    printf("Ilosc znakow to: %d \n", wynik);
    system("pause");
    return 0;
}
