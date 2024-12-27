#pragma once
#include "CsvFile.h"
#include "BinaryFile.h"
#include "IFile.h"
#include <string>

class FileFactory
{
public:
	FileFactory();
	~FileFactory();
    static IFile* OpenFile(const string, const string);
};