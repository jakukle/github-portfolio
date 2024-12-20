#include <stdio.h>
#include <math.h>

int main()
{
	struct punkt {float x; float y;};
// 8 wiersz nadrzedny nad 6 ( 6 zawiera sie w srodku 8 )
    struct okrag {struct punkt o; float r;};
	struct kwadrat {struct punkt a; struct punkt b;};
	
	struct punkt p1,p2;
    struct okrag o1;
    struct kwadrat k1,k2;
   
	char c;
	int a;
	float odleglosc, pkolo, pkwadrat;
	
	printf("wybierz tryb obliczen:\n1.odleglosc miedzy punktami\n");
	printf("2.pole kola\n3.pole kwadratu\n");
	scanf("%d",&a);
	
	
	switch(a)
		{
			case 1:
				printf("podaj wspolrzedne 1 punktu:\n");
				scanf("%f %f", &p1.x, &p1.y);
				printf("podaj wspolrzedne 2 punktu:\n");
				scanf("%f %f", &p2.x, &p2.y);
				odleglosc=sqrt(pow(fabs(p1.x-p2.x),2)+pow(fabs(p1.y-p2.y),2));
				printf("odleglosc miedzy tymi punktami=%f\n",odleglosc);
				break;
				
			case 2:
				printf("podaj wspolrzedne srodka kola i promien:\n");
				scanf("%f %f %f", &o1.o.x, &o1.o.y, &o1.r);
				
				pkolo=M_PI*pow(o1.r,2);
				printf("Pole kola=%f\n",pkolo);
				break;
				
			case 3:
				printf("podaj punkty wyznaczajace przekatna kwadratu:\npunkt1:\n");
				scanf("%f %f", &k1.a.x, &k1.a.y);
				printf("punkt2:\n");
				scanf("%f %f", &k2.b.x, &k2.b.y);
				pkwadrat=sqrt(pow(fabs(k1.a.x-k2.b.x),2)+pow(fabs(k1.a.y-k2.b.y),2))*sqrt(1.0/2.0);
				pkwadrat=pow(pkwadrat,2);
				printf("pole kwadratu=%f", pkwadrat);
				break;
				
		}
		printf("\n\naby zakonczyc wcisnij cos:\n");
		scanf("%c",&c);
		getchar();
		return 0;
}
