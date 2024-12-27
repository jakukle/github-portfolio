#include "BinaryFile.h"

BinaryFile::BinaryFile(const std::string filePath, const std::string mode) : IFile(filePath, mode) // filePath(filePath), length(0)
{
	/*openMode = std::fstream::binary;

	if (mode.find("r") != std::string::npos) openMode |= std::fstream::in;
	if (mode.find("w") != std::string::npos) openMode |= std::fstream::out;
	if (mode.find("a") != std::string::npos) openMode |= std::fstream::app;
	if (mode.find("t") != std::string::npos) openMode |= std::fstream::trunc;
	if (mode.find("e") != std::string::npos) openMode |= std::fstream::ate;

	file.open(filePath, openMode);
	if (file.is_open()) {
		file.seekg(0, std::fstream::end);
		length = file.tellg();
		file.seekg(0, std::fstream::beg);
	}*/
}

BinaryFile::~BinaryFile()
{
	file.close();
}

IFile::Error BinaryFile::Write(const std::vector<Point>& v)
{
	IFile::Error retVal = IFile::Error(ACCESS_DENIED);

	if (!file.is_open())
	{
		retVal = IFile::Error(FILE_INVALID);
	}
	else if (openMode & std::fstream::out)
	{
		file.write((const char *)v.data(), v.size() * sizeof(Point));
		retVal = IFile::Error(SUCCESS);
	}

	return retVal;
}

IFile::Error BinaryFile::Read(std::vector<Point>& v)
{
	IFile::Error retVal = IFile::Error(ACCESS_DENIED);

	if (!file.is_open())
	{
		retVal = IFile::Error(FILE_INVALID);
	}
	else if (openMode & std::fstream::in)
	{
		v.clear();
		v.resize(length / sizeof(Point));
		file.seekg(0, std::fstream::beg);
		file.read((char *)v.data(), length);
		retVal = IFile::Error(SUCCESS);
	}

	return retVal;
}

IFile::Error BinaryFile::Read(Point & p, const unsigned long idx)
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
	else if (openMode & std::fstream::in)
	{
		file.seekg(idx * sizeof(Point));
		file.read((char*)(&p), sizeof(Point));
		retVal = IFile::Error(SUCCESS);
	}

	return retVal;
}
void BinaryFile::WriteLine(const Point& p)
{
	
};
