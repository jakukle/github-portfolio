#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int tab[],int N, int i)
{ 
     int x;
      for(i=0;i<N;i++)
      {
      	if(i==0) {x=tab[i];}
      	else{
      		if(tab[i]>x)x=tab[i];
		  }
	  }

    return x;
    
}

int main()
{	
	int N;
	srand(time(NULL));
	printf("podaj ilosc elementow <=100:\n");
	scanf("%d",&N);
	int tab[N],i;
	
	for(i=0;i<N;i++)
	{
		tab[i]=rand();
		printf("%d\n",tab[i]);
	}
	printf("xmax=%d\n",max(tab,N,i) );
    scanf("%c");
    getchar();
    return 0;
    
}

    
