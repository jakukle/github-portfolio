#include <stdio.h>
#include <math.h>

float licz(float x, int p)
{ 
	float y;
	y=pow(x,p);
    return y;
    
}

int main()
{	
	float x;
	int p;
	printf("podaj x i p:\n");
	scanf("%f%d",&x, &p);
	printf("x^p=%f\n", licz(x,p));
    scanf("%c");
    getchar();
    return 0;
    
}

    
