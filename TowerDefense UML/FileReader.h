#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class FileReader
{
private:
	std::vector<std::vector<int>> _tabFile;
	int _sizeHeight;

public:
	FileReader();

	void readFileTxt(std::string path);
	void readFileCsv(std::string path);
	std::vector<std::vector<int>> getFile();
	int getFileHeight();
};

