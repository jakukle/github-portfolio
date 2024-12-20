#include <stdio.h>
#include <math.h>
// ewfweewerwe //
main()
{
	float x, y, yp;
	printf("Podaj x : ");
	scanf("%f",&x);
	yp=sqrt(x+1);
	printf("%f\n", yp);
	if((yp)>=0)
       {
       	 y=sqrt(x+1);
       	 printf("%f",y);
	   }
	else 
	     printf("Nie da sie");
	return 0;	    
}
