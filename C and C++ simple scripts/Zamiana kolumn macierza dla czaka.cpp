#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <math.h>

main()
     {
           int macierz[2][5],macierzpomoc[2][5], i, j,n,m;
        	printf("Podaj elementy\n");
           for(i=0; i<=1; i++)
            {
              
               for(j=0; j<=4; j++)
               {
                    scanf("%d", &macierz[i][j]);
                    
               }
            }
            printf("Tabelka wyglada tak\n");
            for(i=0; i<=1; i++)
            {
               
               for(j=0; j<=4; j++)
               {
                    printf("%d ", macierz[i][j]);
                    macierzpomoc[i][j]=macierz[i][j];
               }
               printf("\n");
            }
    	printf("Teraz bedziemy zamieniac miejscami kolumny\n");
    	
    	printf("Ktora kolumna? (Podaj od 0 do 4)\n");
    	scanf("%d", &n);
    	printf("Ktora druga kolumna? (Podaj od 0 do 4 ale bez n)\n");
    	scanf("%d", &m);
    		
		if(n<m)
		{
		 printf("Tabelka po zamianie wyglada teraz tak\n");
            for(i=0; i<=1; i++)
            {
               
               for(j=0; j<=4; j++)
               {
               		if (j==n)
               		 {
               		 	macierz[i][n] = macierz[i][m];
               		}
               		if (j==m)
               		{
               		 	macierz[i][m] = macierzpomoc[i][n];	
					}
                    printf("%d ", macierz[i][j]);
               }
               printf("\n");
            }
    	}
    	else 
    	{
    	printf("Tabelka po zamianie wyglada teraz tak\n");
            for(i=0; i<=1; i++)
            {
               
               for(j=0; j<=4; j++)
               {
               		if (j==m)
               		 {
               		 	macierz[i][m] = macierz[i][n];
               		}
               		if (j==n)
               		{
               		 	macierz[i][n] = macierzpomoc[i][m];	
					}
                    printf("%d ", macierz[i][j]);
               }
               printf("\n");
            }
    }

    	
    	
    	
        system("pause");
        return 0;
  } 
