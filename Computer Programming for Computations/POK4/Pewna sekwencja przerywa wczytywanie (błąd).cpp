#include <iostream>
#include <math.h>
#include <stdio.h>

/*main()
{
	int n, licznik=0, zliczacz=0;
	printf("Wczytywanie do momentu trzeciej jedynki\n");
	do
	{
		printf("Podaj liczbe calkowita : ");
		scanf("%d", &n);
		zliczacz++;
		if(n==1)
			licznik++;
	}while(licznik<3);
	
	printf("Ilosc wczytanych liczb to : %d\n", zliczacz-1);
*/	

/*main()
{
	int n, licznik=0, zliczacz=0;
	printf("Wczytywanie do momentu trzeciej z rzedu jedynki\n");
	do
	{
		printf("Podaj liczbe calkowita : ");
		scanf("%d", &n);
		zliczacz++;
		if(n==1)
			licznik++;
		if(n!=1)
			licznik=0;
	}while(licznik<3);
	
	printf("Ilosc wczytanych liczb to : %d\n", zliczacz-1);
*/
/*main()
{
    int i, x = 0, a, b, ilosc = 0, c;
    for( i = 0; i == i; i++ )
    {
        printf( "Podaj liczbe: " );
        scanf( "%d", & a );
        if( i == 0 )
        {
            b = a;
            c = b;
            x++;
        }
        else
        {
            if( a != b && a != c ) //if(a-b) bedzie 0 (te same liczby) to sie nie wykona, ale jesli rozne to jest ok
            {
                x++;
                c = b;
                b = a;
            }
            else
                 x = 1;
           
        }
        ilosc++;
       
        if( x == 3 )
             break;
       
    }
    printf( "Wczytano %d liczb.\n", ilosc );
    */
    main()
{
	int n, licznik=0, zliczacz=0, a1, a2, a3,a,ap,app;
	printf("Wczytywanie do momentu trzech podanych liczb\n");
	printf("Podaj sekwencje (1) : ");
		scanf("%d", &a1);
	printf("Podaj sekwencje (2) : ");
		scanf("%d", &a2);
	printf("Podaj sekwencje (3) : ");
		scanf("%d", &a3);
	printf("Podaj liczbe calkowita : ");
		scanf("%d", &app);
	printf("Podaj liczbe calkowita : ");
		scanf("%d", &ap);
	do
	{
		printf("Podaj liczbe calkowita : ");
		scanf("%d", &n);
		zliczacz++;
		if(app==a1)
			if(ap==a2)
				if(n==a3)
					licznik=3;
		app=ap;
		ap=n;
	}while(licznik<3);
	
	printf("Ilosc wczytanych liczb to : %d\n", zliczacz+2);
    system( "pause" );
    return 0;
}

