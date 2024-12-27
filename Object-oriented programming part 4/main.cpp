#include "BinaryFile.h"
#include "CsvFile.h"
#include "FileFactory.h"

using namespace std;

int main()
{
	IFile* file = FileFactory::OpenFile("test.csv", "a");
	vector<Point>v;
	Point p1(997, 112, 7), p2(1, 3, 5), p3(4, 0, 9);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	file->Write(v);
	cout << "rozmiar:"<<v.size()<<endl;
	delete file; 

	IFile* plik = FileFactory::OpenFile("test.csv", "r");
	vector<Point> x;
	plik->Read(x);
	delete plik;

	IFile* pliczek = FileFactory::OpenFile("test.csv", "r");
	Point y;
	long dl = 9;
	pliczek->Read(y, dl);
	delete pliczek;
	
	return 0;
}