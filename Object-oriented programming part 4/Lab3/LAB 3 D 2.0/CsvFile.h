#pragma once
#include <fstream>
#include <vector>
#include "Point.h"
#include "IFile.h"
#include <sstream>
#include <string>
#include <iostream>
using namespace std;
class CsvFile : public IFile
{	
public:
	CsvFile(const string, const string);
	~CsvFile();

	IFile::Error Write(const vector<Point>&) override;
	IFile::Error Read(vector<Point>&) override;
	IFile::Error Read(Point&, const unsigned long) override;
	
private:
	void WriteLine(const Point&);
    vector<string> Split(string str, char delim);
};

