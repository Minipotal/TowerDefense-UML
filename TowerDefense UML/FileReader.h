#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <string>
#include "Vect.h"

class Towers;
class Ennemies;

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
	Ennemies* getEnnemie(int id, Vect2 size);
	Towers* getTower(int id);
	int getFileHeight();

private:
	std::vector<std::vector<std::string>> readFileCsv(std::string path);
	int randint(int a, int b);
	int stringToHex(std::string str);
};

