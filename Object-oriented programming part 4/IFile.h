#pragma once
#include <fstream>
#include <vector>
#include "Point.h"
using namespace std;
class IFile
{
protected :
	fstream file;
	string filePath;
	unsigned long length;
	fstream::openmode openMode;
    virtual void  WriteLine(const Point& p)=0;
public :
	enum Error {
		SUCCESS, ACCESS_DENIED, OUT_OF_BOUNDS, FILE_INVALID
	};
	IFile(const string , const string);
	virtual ~IFile();
	
	virtual Error Write(const vector<Point>&)=0;
	virtual Error Read(vector<Point>&)=0;
	virtual Error Read(Point&, const unsigned long)=0;
};
