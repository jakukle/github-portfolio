#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef float macierz [20][20];

void trans(macierz a,int n)
{
    
      int i,j,k,l,x,y;
      float max;
      x=1;
      y=1;
     
      for(i=0;i<n;i++)
      		for(j=0;j<n;j++)
                if(i==0 && j==0)
						  {
						  max=a[i][j];
						  k=i;
						  l=j;
						  }
						  else if(a[i][j]>max)
						  {
							max=a[i][j];
							k=i;
							 l=j;
						 }
					printf("max=a[%d][%d]=%f\n",k,l,max);
	
	
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
