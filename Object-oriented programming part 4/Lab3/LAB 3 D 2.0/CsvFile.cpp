#include "CsvFile.h"
using namespace std;

CsvFile::CsvFile(const string filePath, const string mode) : IFile(filePath, mode) {}

CsvFile::~CsvFile() {}

void CsvFile::WriteLine(const Point& p)
{
	 file << p.x << "," << p.y << "," << p.z << endl; 
};

vector<string> CsvFile::Split(string a, char b)
{
	vector<string> rezultat; stringstream x(a); string pozycja;
	while (getline(x, pozycja, b))
		rezultat.push_back(pozycja);
	return rezultat;
}

IFile::Error CsvFile::Write(const vector<Point>& v)
{
	IFile::Error retVal = IFile::Error(ACCESS_DENIED);

	if (!file.is_open())
	{
		retVal = IFile::Error(FILE_INVALID);
	}
	else if (openMode & fstream::app)
	{
	
	for (int i = 0; i < v.size(); i++)
	{
		WriteLine(v[i]);
	}
	
	/*
	for(int i=0;i<v.size();i++)
	{
		file<<v[i].x<<";";
		file<<v[i].y<<";";
		file<<v[i].z<<";"<<endl;
	}
	*/
		retVal = IFile::Error(SUCCESS);

	}

	return retVal;
}

IFile::Error CsvFile::Read(vector<Point>& v)
{
	IFile::Error retVal = IFile::Error(ACCESS_DENIED);

	if (!file.is_open())
	{
		retVal = IFile::Error(FILE_INVALID);
	}
	else if (openMode & fstream::in)
	{

		string linia;
		Point p;
		//file.seekg(0, fstream::beg);
		while (!file.eof()/*getline(file,linia)*/)
		{

			//rozbijanie linijki 
			//std::string::find
			//Split
			if (getline(file, linia, ',')) {
				p.x = stod(linia);
				getline(file, linia, ',');
				p.y = stod(linia);
				getline(file, linia, '\n');
				p.z = stod(linia);

				v.push_back(p);
			}
		}
		retVal = IFile::Error(SUCCESS);
		
	}
	return retVal;
}
IFile::Error CsvFile::Read(Point& v, const unsigned long idx)
{
	IFile::Error retVal = IFile::Error(ACCESS_DENIED);

	if (!file.is_open())
	{
		retVal = IFile::Error(FILE_INVALID);
	}
	else if (idx * sizeof(Point) > length)
	{
		retVal = IFile::Error(OUT_OF_BOUNDS);
	}
	else if (openMode & fstream::in)
	{
		string linia;
	
		file.seekg(0, fstream::beg);
		for (int i = 0; i < idx; i++)
		{
		    if (idx * sizeof(Point) > length)
	        {
		       retVal = IFile::Error(OUT_OF_BOUNDS);
		       return retVal;
	        }
			else
			file.ignore(100, '\n');
		}
		getline(file, linia, ',');
		v.x = stod(linia);
		getline(file, linia, ',');
		v.y = stod(linia);
		getline(file, linia, '\n');
		v.z = stod(linia);
		retVal = IFile::Error(SUCCESS);
	}

	return retVal;
}