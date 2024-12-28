#include <stdio.h>
#include <stdlib.h>

int x;

int main()
{
   int liczba, liczbunia;
   printf("Podaj liczbe: ");
   scanf("%d",&liczba);
   printf("Podales liczbe %d \n",liczba);
   printf("Podaj liczbunie: ");
   scanf("%d", &liczbunia);
   printf("Podales liczbunie %d \n",liczbunia);
   printf("Podaj wartosc x : ");
   scanf("%d", &x);
switch(x)
{
	case 1: 
	        printf("%d\n", liczba+liczbunia);
	        break;
	case 2:
	        printf("%d\n", liczba-liczbunia);
	        break;
	case 3:
	        printf("%d\n", liczba*liczbunia);
	        break;
	case 4: 
            if(liczbunia==0)
			printf("NIE WOLNO PRZEZ 0 TYPIE\n");
			else	
	        printf("%d\n", liczba/liczbunia);
			break;	
			       
			       
   }   
 
  return 0; 
} 

