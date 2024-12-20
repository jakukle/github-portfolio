#include <stdio.h>

float licz(int n)
{ 
	float y=1;
	int i;
	for(i=1;i<=n;i++)
	{
		y=y*i;
	}
    return y;
    
}

int main()
{	
	int n;
	printf("podaj n:\n");
	scanf("%d",&n);
	printf("n!=%f\n", licz(n));
    scanf("%c");
    getchar();
    return 0;
    
}

    
