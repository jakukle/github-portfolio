#include <stdio.h>

int main()
{
    float x;
    FILE *dane;
    FILE *dane1;
    FILE *dane2;
    dane=fopen("dane.txt","r");
    dane1=fopen("dane1.txt","a");
    dane2=fopen("dane2.txt","a");
    
    while(fscanf(dane,"%f",&x)==1)
               {             
                  if(x>0) fprintf(dane1,"%f\n",x);
                  else
                  {if(x<0) fprintf(dane2,"%f\n",x);};
               };
    fclose(dane);
    fclose(dane1);
    fclose(dane2);
    
    printf("wartosci >0 - dane1.txt\nwartosci <0 - dane2.txt");
    getchar();
return 0;
}
