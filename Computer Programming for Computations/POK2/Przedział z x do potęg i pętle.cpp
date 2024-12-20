#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
   float x, p, k, i=0, pomoc=0;
printf("Podaj p = ");
   scanf("%f",&p);
printf("Podaj k = ");
   scanf("%f",&k);
printf("Podaj x = ");
   scanf("%f",&x);
if (p>k)
{
             pomoc=p;
        	 p=k;
        	 k=pomoc;
         printf("%f - to jest k\n", k);
         printf("%f - to jest p\n", p);
         
     if( x>=p && x<=k )
   {
      while( i<3)
      {
                i++;
                printf("x = %0.1f\n", pow(x,i));
                }
       }
       else
       printf("Podany x nie jest w przedziale zadeklarowanym przez ciebie\n");
}

else 

{
     if( x>=p && x<=k )
   {
      while( i<3)
      {
                i++;
                printf("x = %0.1f\n", pow(x,i));
                }
       }
       else
       printf("Podany x nie jest w przedziale zadeklarowanym przez ciebie\n");
}
system("PAUSE");              
return 0;
}
