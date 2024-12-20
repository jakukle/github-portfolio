#include <stdio.h>
#include <string.h>

void funkcja(char znaki[256])
{
     int n=strlen(znaki);
     int k=n-1;
     int i;
     char tmp;
    for(i=0; i<n/2; i++)
    {
             tmp=znaki[i];
             znaki[i]=znaki[k];
             znaki[k]=tmp;
             k--;
    }
   
   
    for(i=0; i<n; i++)
    {
             if((int) znaki[i]>=97 && (int) znaki[i]<=122)
             {
                             znaki[i]=(int)znaki[i]-32;
             }
             else{
			 		if((int) znaki[i]>=65 && (int) znaki[i]<=90)
            		 {
                             znaki[i]=(int)znaki[i]+32;
            		 }
				 }
    } 
     for(i=0; i<n; i++)
    {
             printf("%c", znaki[i]);
    }
    printf("\n");
}

int main()
{
    FILE *plik;
    plik=fopen("tekst.txt", "rt");
    char a[256];
    while(fscanf(plik, "%s", &a)==1)
    {
                                 funkcja(a);
    }
                        
    system("Pause");
    return 0;
}
    
