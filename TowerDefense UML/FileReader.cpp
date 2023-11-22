#include "FileReader.h"


FileReader::FileReader() {};

void FileReader::readFileTxt(std::string path)
{
    _sizeHeight = 0; // 0 le nombre de vagues
    std::fstream newfile;
    std::string result = "";

    newfile.open(path, std::ios::in); //open a file to perform read operation using file object

    if (newfile.is_open()) { //checking whether the file is open
        std::string tp;
        while (getline(newfile, tp)) { //read data from file object and put it into string.
            if (tp.size() != 0 && tp[0] != '/') // Vérifications pour ne pas les valeurs dans notre reader
            {
                if (tp[0] != '#')
                {
                    result += tp;
                }
                else
                {
                    result += "#";
                    _sizeHeight += 1;
                    _tabFile.resize(_sizeHeight);
                }
            }
        }
    }
    newfile.close(); //close the file object.

    /* incrémentation du tableau à parti des valeurs présentes dans le fichier txt */

    int value = 0;
    int i = -1; // commence à -1 pour faire des additions pour le nombre de vagues

    for (int j = 0; j < result.size(); j++)
    {
        if (result[j] == '#')
        {
            i++;
        }
        else if (i < _sizeHeight) // vérifie que l'on reste dans les deux vagues
        {
            int o = j;
            int gap = 0;
            while (result[o + gap] != 'x')
            {
                if (o + gap - j > 0)
                {
                    value = value * 10;
                }
                value += (result[o + gap] - 48);
                gap++;
            }
            for (int k = 0; k < value; k++)
            {
                _tabFile[i].push_back(result[j + gap + 1] - 48);
            }
            j += gap + 1;
        }
        value = 0;
    }

    //for (int i = 0; i < _sizeHeight; i++)
    //{
    //    for (int j = 0; j < _tabFile[i].size(); j++)
    //    {
    //        std::cout << _tabFile[i][j];
    //    }
    //    std::cout << std::endl;
    //}
}

std::vector<std::vector<int>> FileReader::getFile()
{
    return _tabFile;
}

int FileReader::getFileHeight()
{
    return _sizeHeight;
}