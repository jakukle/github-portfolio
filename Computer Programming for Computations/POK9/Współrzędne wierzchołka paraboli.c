#include <stdio.h>

void wierzcholek(float a, float b, float c, float *p, float *q)
{    
     float d;
     d=(b*b)-(4*a*c);
     *p=(-b)/(2*a);
     *q=(-d)/(4*a);
}

int main()
{
    float a,b,c,p,q;
    
    printf("podaj wpolczynniki a,b i c:\n");
    scanf("%f%f%f",&a,&b,&c);
    wierzcholek(a,b,c,&p,&q);
    printf("p=%f\nq=%f\n",p,q);
    scanf("%c");
    getchar();
    return 0;
}
