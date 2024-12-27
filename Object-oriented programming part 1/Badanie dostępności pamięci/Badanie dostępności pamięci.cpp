#include <iostream>
#include <new>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
    int MEGA = 1024 * 1024, STEP = 100 * MEGA;
	for (int nSize = STEP; ; nSize += STEP)
	{
		try
		{
			char* cBuf = new char[nSize];
			delete [] cBuf;
		}
		catch (bad_alloc)
		{
			cout << "Nie udalo sie: " << setw(4) << nSize / MEGA << " MB" << endl; // Nie wiem po co te setw(4). Bez tego też jakby działą
			exit(1);
		}
		cout << "Udalo sie: " << setw(4) << nSize / MEGA << " MB" << endl;
	}
	
	return 0; 
   
}

