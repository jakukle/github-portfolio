#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef float macierz [20][20];

void trans(macierz a,int n)
{
    
      int i,j,k,l,x,y;
      float max, min;
      printf("max(1) czy min(0)?\n");
      scanf("%d",&x);
      printf("pierwsze(1) czy ostatnie(0) wystapienie?\n");
      scanf("%d",&y);
      if(x==1)
      {
	  	for(i=0;i<n;i++)
      		{
                      for(j=0;j<n;j++)
                      {
                      	if(y==1)
                      	{	
						  if(i==0 && j==0){max=a[i][j];k=i;l=j;}
                      		else{
						  		if(a[i][j]>max){max=a[i][j];k=i;l=j;};
						  		};
						  }
						  else{
						  	if(i==0 && j==0){max=a[i][j];k=i;l=j;}
                      		else{
						  		if(a[i][j]>=max){max=a[i][j];k=i;l=j;};
						 		 };
					  };
      				};
	 	  	};
	 	  	printf("max=a[%d][%d]=%f\n",k,l,max);
		}
		else{if(x==0)
				{
					for(i=0;i<n;i++)
      				{
                      for(j=0;j<n;j++)
                      {
                      	if(y==1)
                      	{	
						  if(i==0 && j==0){min=a[i][j];k=i;l=j;}
                      		else{
						  		if(a[i][j]<min){min=a[i][j];k=i;l=j;};
						  		};
						  }
						  else{
						  	if(i==0 && j==0){min=a[i][j];k=i;l=j;}
                      		else{
						  		if(a[i][j]<=min){min=a[i][j];k=i;l=j;}
						 		 };
					  			};
      					};
	 	  			};
					
				};
			printf("min=a[%d][%d]=%f\n",k,l,min);
			};
	
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
                      }   ;
                      printf("\n");
      };
       printf("\n\n\n");
      trans(a,n);
      
 scanf("%c");
   getchar();
 return 0;     
}
      
