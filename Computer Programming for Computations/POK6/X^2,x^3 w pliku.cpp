#include <stdio.h>

int main()
{ 
    float x,xk,dx,x2,x3;
    FILE *plik;
    plik=fopen("wynik.txt", "a+");
    printf("podaj xp, xk i dx\n");
    scanf("%f%f%f",&x, &xk, &dx);
    
    for(x;x<=xk;x=x+dx)
                      { x2=x*x;
                        x3=x*x*x;
                        fprintf(plik,"%f\t %f\t %f\n",x, x2, x3);
                        };
    fclose(plik);
 getchar();                       
 return 0;                       
}
                         
    
