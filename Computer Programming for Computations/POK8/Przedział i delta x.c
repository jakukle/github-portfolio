#include <stdio.h>

float x(float xp, float xk, float dx)
{
      float eps=dx/1000;
      for(xp;xp<=xk+eps;xp=xp+dx)
      {
         printf("x=%f\n",xp);}
     
}

int main()
{
    float xp,xk,dx;
    printf("podaj xp, xk, dx:\n");
    scanf("%f%f%f",&xp,&xk,&dx);
    x(xp,xk,dx);
    scanf("%c");
    getchar();
    return 0;
}
