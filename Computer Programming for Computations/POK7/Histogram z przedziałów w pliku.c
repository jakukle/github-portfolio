#include <stdio.h>

int main()
{
	FILE* dane;
	FILE* histogram;
	dane=fopen("dane.txt","r");
	histogram=fopen("histogram.txt","a+");
	int i=0,N=0;
	float x,y;
	
	printf("podaj ilosc przedzialow (max 10):\n");
	scanf("%d",&N);
	float a[N];
	int b[N];
	for(i=0;i<N;i++)
		{a[i]=0;b[i]=0;};
	
	for(i=0;i<=N;i++)
		{
		if(i==0){a[i]=-3;}
		else {a[i]=a[i-1]+(6/(float)N);};	
		};
		
	while(fscanf(dane,"%f",&x)==1)
		{
			for(i=0;i<N;i++)
			{
				if(x>a[i] && x<=a[i+1])b[i]++;
			};
		
		};
	
	for(i=0;i<N;i++)
	{
	printf("przedzial %f - %f\t ilosc: %d\n",a[i],a[i+1],b[i]);
	fprintf(histogram,"przedzial %f - %f\t ilosc: %d\n",a[i],a[i+1],b[i]);
	}
	fclose(dane);
	fclose(histogram);
	printf("aby zakonczyc wcisnij cos:\n");
	scanf("%c");
	getchar();
	return 0;
}
