#include <iostream>
#include <math.h>
#include <stdio.h>

main()
{
	float N1,N2,i,j,p,k,x,iloczyn=1, suma5=0, suma2=0,suma3=0,suma4=0,y,u,suma=0,wyrazenie,wyrazenie2;
	printf("Sumy w sumach i iloczyny\n");
	printf("Podaj N1 : ");
	scanf("%f", &N1);
	printf("Podaj N2 : ");
	scanf("%f", &N2);
	printf("Podaj x : ");
	scanf("%f", &x);
	
	for(i=1; i<=N1; i++)
	{
		suma2=0;
			for(j=-2; j<=i+3; j++)
			{
				suma3=0;
				
					for(p=1; p<=10; p++)
					{	
						iloczyn=1;
							for(k=1; k<=p+N2; k++)
									{
  									u = cos(k*(2+p-x));
									iloczyn = iloczyn * u;
	    							}
	    					suma3 = suma3 + iloczyn;
	               }
	    				y=sin(j*x);
						suma2 = suma2 + y;
						suma4=suma2 + suma3;
		}
			suma5 = suma5 + suma4;
				
	}
	printf("Wartosc wynosi : %f\n", suma5);

	suma2=0;
	suma3=0;
	suma4=0;
	suma5=0;
	iloczyn=1;
	
	 for(i=1;i<=N1;i++)
        {
        suma2=0;
            for(j=-2;j<=i+3;j++)
                {
                    suma=0;
                        for(p=1;p<=10;p++)
                            {
                                iloczyn=1;
                                    for(k=1;k<=p+N2;k++)
                                        {
                                            wyrazenie=cos(k*(2+p-x));
                                            iloczyn=iloczyn*wyrazenie;
                                        }
                                //printf("iloczyn dla p=%d wynosi: %f ",p,iloczyn);
                                suma=suma+iloczyn;
                                //printf("a suma iloczynow wynosi: %f\n",suma);
                            }
                    //printf("wartosc funkcji wynosi: %f\n\n",suma);
                    wyrazenie2=sin(j*x);
                    suma2=suma2+wyrazenie2;
                    suma3=suma2+suma;
                }
                suma4=suma4+suma3;
        }

    printf("wartosc funkcji wynosi: %f\n",suma4);

	system("pause");
	return 0;
}
