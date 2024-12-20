#include <stdio.h>
#include <math.h>

int main()
{   
    int N=0,a=0,b=0,c=0;
    float x,srednia=0,suma=0,suma1=0,d,odchylenie=0;
    FILE* dane;
    FILE* raport;
    dane=fopen("dane.txt","r");
    raport=fopen("raport.txt","a+");
    
    while(fscanf(dane,"%f",&x)==1)
                {
                suma=suma+x;
                N++;
                }
                srednia=suma/N;
                printf("srednia %f\n", srednia);
    fseek(dane,0,0);
    while(fscanf(dane,"%f",&x)==1)
                {
                suma1=suma1+pow((srednia-x),2); 
                }
                odchylenie=sqrt(suma1/(float)(N-1));
                printf("odchylenie %f\n", odchylenie);
     fseek(dane,0,0);       
     while(fscanf(dane,"%f",&x)==1)
                {
                if(x>=(srednia-odchylenie) && x<=(srednia+odchylenie)){a++;};
                if(x>=(srednia-2*odchylenie) && x<=(srednia+2*odchylenie)){b++;};
                if(x>=(srednia-3*odchylenie) && x<=(srednia+3*odchylenie)){c++;};
                }
                printf("a=%d, b=%d, c=%d",a,b,c);
    fprintf(raport,"przedzial 1 - %d liczb\n",a);     
    fprintf(raport,"przedzial 2 - %d liczb\n",b);   
    fprintf(raport,"przedzial 3 - %d liczb\n",c);  
    getchar();
    fclose(dane);
    fclose(raport);
    return 0;
}            
                
