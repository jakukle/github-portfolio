#include <iostream>
using namespace std;
int main()
{
 /*unsigned short*/ int ocena;
 cout<<"Wprowadz ocene :\n";
 cin>>ocena;
 switch(ocena)
 {
 case 1:
 cout<<"Pala\n";
 break;
 case 2:
 cout<<"Bardzo slabo\n";
 break;
 case 3:
 cout<<"Trojka to dobra ocena\n";
 break;
 case 4:
 cout<<"Czworka to bardzo dobra ocena\n";
 break;
 case 5:
 cout<<"Piatka to super ocena\n";
 break;
 case 6:
 cout<<"Szostka to najfajniejsza ocena\n";
 break;
 default:
 cout<<"To nie jest ocena\n";
 }

 return 0;
} 
