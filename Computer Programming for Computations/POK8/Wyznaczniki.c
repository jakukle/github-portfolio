#include <stdio.h>

float wyznacznik(float a, float b, float c, float d)
{ 
      float W;
      W=(a*d)-(b*c);
      return W;
}

int main()
{
    float e,f,g,h,i,j,W,Wx,Wy,x,y;
    printf("podaj wspolczynniki przy x i y oraz wyrazy wolne:\n");
    scanf("%f%f%f%f%f%f",&e,&f,&g,
                         &h,&i,&j);
    W=wyznacznik(e,f,h,i);
    Wx=wyznacznik(g,f,j,i);
    Wy=wyznacznik(e,g,h,j);
    if(W!=0)
    	{
		x=Wx/W;
    	y=Wy/W;
		}
		else{
			if(Wx!=0 && Wy!=0) printf("uklad sprzeczny\n");
			else{ printf("uklad sprzeczny lub nieoznaczony\n");
			}
		}
    printf("x=%f\ny=%f\n",x,y);
    printf("\n%f", W);
    scanf("%c");
    getchar();
    return 0;
}

    
