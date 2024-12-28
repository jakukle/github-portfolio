#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    int tab[3][4][5]; 

	tab[0][0][0] = 23;
	tab[0][1][1]=182;
	tab[3][0][4]=981;
	
	cout<<tab[0][1][1]<<endl;
	cout<<tab[3][0][4]<<endl;

	system("pause");
	return 0;
}

