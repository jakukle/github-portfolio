#include "IFile.h"

IFile::IFile(const string filePath, const string mode) {

	if (mode.find("r") != string::npos) openMode |= fstream::in;
	if (mode.find("w") != string::npos) openMode |= fstream::out;
	if (mode.find("a") != string::npos) openMode |= fstream::app;
	if (mode.find("t") != string::npos) openMode |= fstream::trunc;
	if (mode.find("e") != string::npos) openMode |= fstream::ate;
	if (mode.find("b") != string::npos) openMode |= fstream::binary;

	file.open(filePath, openMode);
	if (file.is_open()) {
		file.seekg(0, std::fstream::end);
		length = file.tellg();
		file.seekg(0, std::fstream::beg);
	}
}
IFile::~IFile() {
	file.close();
};
