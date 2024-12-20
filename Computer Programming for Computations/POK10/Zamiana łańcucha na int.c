#include <stdio.h>
#include <string.h>

void funkcja(char tab[])
{
     int i,liczba=0,n;
     n=strlen(tab);
     for(i=0;i<n;i++)
     {
                               liczba=liczba + (tab[i]- '0') * (int)(pow(10,n-1-i));
                               }
                               printf("%d",liczba);




}

int main()
{
    char tab[10]={0};
    printf("podaj lancuch cyfr\n");
    gets(tab);
    funkcja(tab);
    
    getchar();
    return 0;
}





