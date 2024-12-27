#include <iostream>
#include "List.h"
#include "Point.h"

using namespace std;

int main()
{
	int i;
	while (1)
	{
		List* WskaznikNaPunkty = new List;
		for (i= 0; i < 1000; i++)
		{
			Point p(i, i, i);
			WskaznikNaPunkty->push_back(p);
		}
		delete WskaznikNaPunkty; 
		WskaznikNaPunkty = 0;
	}
	return 0;
}