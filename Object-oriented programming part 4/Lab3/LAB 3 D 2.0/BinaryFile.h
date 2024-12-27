#pragma once
#include <fstream>
#include <vector>
#include "Point.h"
#include "IFile.h"
using namespace std;
class BinaryFile : public IFile
{	
public:
	BinaryFile(const string, const string);
	~BinaryFile();

	IFile::Error Write(const vector<Point>&);
	IFile::Error Read(vector<Point>&);
	IFile::Error Read(Point&, const unsigned long);
private:
	void WriteLine(const Point&);
};

