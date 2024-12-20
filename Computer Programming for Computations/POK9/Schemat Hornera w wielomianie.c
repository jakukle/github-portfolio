#include <stdio.h>

float f(float a[], float x, int n)
{
      float w=0;
	  for(n;n>=0;n--)
                     w=(w*x)+a[n];                            
       return w;
}

int main()
{
    int i,n;
    float x;
    printf("podaj stopien wielomianu:\n");
    scanf("%d",&n);
    float a[n+1];
    for(i=0;i<=n;i++)
    {
    printf("podaj wspolczynnik a%d:\n",i);
    scanf("%f",&a[i]);
    }
    printf("podaj x:\n");
    scanf("%f",&x);
    printf("%f",f(a,x,n));
    scanf("%c");
    getchar();
    return 0;
}
                          
                      
