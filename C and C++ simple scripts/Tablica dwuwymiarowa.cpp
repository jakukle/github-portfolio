#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <math.h>

main()
     {
           int tabelka[3][3], i, j;
        	printf("Podaj elementy\n");
           for(i=0; i<3; i++)
            {
              
               for(j=0; j<3; j++)
               {
                    scanf("%d", &tabelka[i][j]);
                    
               }
            }
            printf("Tabelka wyglada tak\n");
            for(i=0; i<3; i++)
            {
               
               for(j=0; j<3; j++)
               {
                    printf("%d ", tabelka[i][j]);
               }
               printf("\n");
            }
        system("pause");
        return 0;
  } 
