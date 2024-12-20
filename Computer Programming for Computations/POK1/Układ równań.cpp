#include <stdio.h>
#include <math.h>
float a11,a12,b1,a21,a22,b2,W,Wx,Wy,x,y;
char k;
int main()
{
printf("Aby rozwiazac ponizszy uklad rownan metoda wyznacznikowa\nz 2 niewiadomymi x i y\n");
printf("{a11*x+a12*y=b1\n");
printf("{a21*x+a22*y=b2\n");
printf("podaj a11,a12,b1,a21,a22,b2");
scanf("%f%f%f%f%f%f",&a11,&a12,&b1,&a21,&a22,&b2);
printf("uklad rownan wyglada nastepujaco\n");
printf("{%fx+%fy=%f\n{%fx+%fy=%f\n",a11,a12,b1,a21,a22,b2);
W=(a11*a22)-(a12*a21);
Wx=(b1*a22)-(a12*b2);
Wy=(a11*b2)-(b1*a21);
printf("W=%f\nWx=%f\nWy=%f\n",W,Wx,Wy);
if(W!=0)
			{
			printf("uklad oznaczony\n");
			x=Wx/W;
			y=Wy/W;
			printf("x=%f,y=%f",x,y);
			};
if(W==0&&(Wx!=0||Wy!=0))
			{
			printf("uklad sprzeczny, brak rozwiazan");	
			};
if(W==0&&Wx==0&&Wy==0)
			{
			printf("uklad nieoznaczony, nieskonczenie wiele rozwiazan");
			};			
}
