#include <stdio.h>
#include <math.h>

float silnia(int i)
{ 
	float y=1;
	int a;
	for(a=0;a<=i;a++)
	{
		if(a==0)y=1;
		else
		{y=y*a;}
	}
    return y;
    
}

float potega(float x, int i)
{ 
	float z;
	if(x>=0)
	{z=pow(x,i);}
	else
	{
	x=-x; 
	 if(i%2==1) 
		z=-pow(x,i);
	 else z=pow(x,i);
	}
    return z;
    
}

int main()
{	
	int n,i;
	float suma=0,e,x;
	printf("podaj n i x:\n");
	scanf("%d%f",&n,&x);
	
	for(i=0;i<=n;i++)
	{
		suma=suma+(potega(x,i)/silnia(i));	
	}
	e=exp(x);
	printf("e=%f\nsuma=%f",e,suma);
    scanf("%c");
    getchar();
    return 0;
    
}

    
