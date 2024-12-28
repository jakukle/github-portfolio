#include <stdio.h>
/* program sprawdza czy podana liczba jest dodatnia czy ujemna */
 
int main()
{
   int liczba;
 
   printf("Podaj liczbe: ");
   scanf("%d",&liczba);
 
   if( liczba > 0 )
      printf("Liczba %d jest wieksza od zera\n",liczba);
   else if( liczba == 0 )
      printf("Liczba %d jest rowna zeru",liczba);   
   else
      printf("Liczba %d jest mniejsza od zera\n",liczba);
 
   return 0;
}
