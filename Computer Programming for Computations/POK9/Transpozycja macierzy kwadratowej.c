#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef float macierz [20][20];

float trans(macierz a,int n)
{
      macierz b;
      int i,j;
      
      for(i=0;i<n;i++)
      {
                      for(j=0;j<n;j++)
                      { b[i][j]=a[j][i];
                       printf("%.0f\t",b[i][j]);}   
                      printf("\n");
      }
}    
int main()
{ int i,j,n;
  macierz a;
  printf("podaj rozmiar:\n");
  scanf("%d",&n);
  srand(time(NULL));
   for(i=0;i<n;i++)
      {
                      for(j=0;j<n;j++)
                      { a[i][j]=rand()%100;
                        printf("%.0f\t",a[i][j]);
                      }   
                      printf("\n");
      }
       printf("\n\n\n");
      trans(a,n);
      
 scanf("%c");
   getchar();
 return 0;     
}
      
