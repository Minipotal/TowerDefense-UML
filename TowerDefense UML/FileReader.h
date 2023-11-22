#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <string>

class FileReader
{
private:
	std::vector<std::vector<int>> _tabFile;
	std::vector<std::vector<std::string>> _tabEnnemies;
	std::vector<std::vector<std::string>> _tabTower;
	int _sizeHeight;

public:
	FileReader();

	void readFileTxt(std::string path);
	void readFileEnnemie(std::string path);
	void readFileTower(std::string path);
	std::vector<std::vector<int>> getFile();
	int getFileHeight();

private:
	std::vector<std::vector<std::string>> readFileCsv(std::string path);
};

