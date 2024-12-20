#include <stdio.h>
#include <math.h>

float funkcja(float x, float y)
{
 float f;
 if(x<y) f=2*x+2*y;
         else{if(x==y)f=3;
                          else{if(x>y) f=pow(x,2)-sin(y);};};
 return f;
}       

int main()
{
    float x0,y0,dx,dy,y=0;
    int Np,Nk;
    printf("podaj x0,y0,dx,dy,Np,Nk:\n");
    scanf("%f%f%f%f%d%d",&x0,&y0,&dx,&dy,&Np,&Nk);
    
    for(Np;Np<=Nk;Np++)
    {
                       y=y+funkcja(x0+(Np*dx),y0-(Np*dy));
    };
   printf("y=%f",y);
   scanf("%c");
   getchar();
   return 0;
}                   
