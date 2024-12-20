#include <stdio.h>
#include <math.h>

int main()
{
	struct wektor {float x1,y1,x2,y2,s;} w[20];
	int i=0,k,l;
	float wmax,wmin;
	
	for(i;i<20;i++)
		{
			printf("podaj wspolrzedne wektora nr %d:\npoczatek (x,y):\n",i);
			scanf("%f %f", &w[i].x1, &w[i].y1);
			printf("koniec (x,y):\n");
			scanf("%f %f", &w[i].x2, &w[i].y2);
			w[i].s=sqrt(pow(fabs(w[i].x1-w[i].x2),2)+pow(fabs(w[i].y1-w[i].y2),2));
			
			if(i==0)
			 	{
				 wmax=w[i].s; k=i;
				 wmin=w[i].s; l=i;
				 }
				 else{
				 	if(w[i].s>wmax)
					  {wmax=w[i].s;k=i;}
				 	else{if(w[i].s<wmin) 
					 	{wmin=w[i].s;l=i;};
						 };
				 	  };
		};
			for(i=0;i<20;i++)
			{
				printf("struktura %d: x1=%f y1=%f x2=%f y2=%f s=%f\n",i, w[i].x1,w[i].y1,w[i].x2,w[i].y2,w[i].s);
			};
		
	printf("najdluzszy wektor to nr %d, dlugosc=%f\n",k,wmax);
	printf("najkrotszy wektor to nr %d, dlugosc=%f\n",l,wmin);
	getchar();
  
    return 0;
}
                       
