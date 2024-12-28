#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main()
{   
    int i;
    float x,y,z;
    FILE *dane;
    dane=fopen("dane.txt","a+");
    srand(time(NULL));
    
    for(i=0;i<100;i++)
    {                 
                      x=0;
                      z=0;
                      y=0;
                      x=(rand()+1.0)/((float)RAND_MAX+1.0);
                      y=(rand()+1.0)/((float)RAND_MAX+1.0);
                      z=sin(2*M_PI*y)*sqrt(-2*log(x));
                      fprintf(dane,"%f\n",z);
    };
    fclose(dane);
    
    return 0;
}
                      
    

