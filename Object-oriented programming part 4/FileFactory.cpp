#include "FileFactory.h"
FileFactory::FileFactory()
{};

FileFactory::~FileFactory()
{};

IFile *FileFactory::OpenFile(string filePath, string mode) 
{
	IFile* file = nullptr;

	if (filePath.substr(filePath.find_last_of(".")+1) == "bin")
		file = new BinaryFile(filePath, mode+"b");
	else if (filePath.substr(filePath.find_last_of(".") + 1) == "csv")
		file = new CsvFile(filePath, mode);

	return file;

};
