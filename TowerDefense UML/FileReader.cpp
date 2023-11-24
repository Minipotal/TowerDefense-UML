#include "FileReader.h"

#include "Ennemies.h"
#include "Towers.h"
#include "Vect.h"

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

std::vector<std::vector<std::string>> FileReader::readFileCsv(std::string path)
{
    std::vector<std::vector<std::string>> list;
    std::fstream newfile;
    std::vector<std::string> result;

    newfile.open(path, std::ios::in); //open a file to perform read operation using file object

    if (newfile.is_open()) { //checking whether the file is open
        std::string tp;
        while (getline(newfile, tp)) { //read data from file object and put it into string.
            if (tp.size() != 0) // Vérifications pour ne pas les valeurs dans notre reader
            {
                result.resize(result.size() + 1);
                result[result.size() - 1] = tp;
                list.resize(list.size() + 1);
            }
        }
    }
    newfile.close(); //close the file object.

    int i = 0;

    for (std::string line : result)
    {
        std::string delimiter = ",";

        size_t pos = 0;
        std::string token;

        int j = 0;

        while ((pos = line.find(delimiter)) != std::string::npos) {
            token = line.substr(0, pos);
            line.erase(0,pos + delimiter.length());

            list[i].resize(j + 1);
            list[i][j] = token;

            j++;
        }
        token = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());

        list[i].resize(j + 1);
        list[i][j] = token;
        i++;
    }

    return list;
}

void FileReader::readFileEnnemie(std::string path)
{
    _tabEnnemies = this->readFileCsv(path);
}

void FileReader::readFileTower(std::string path)
{
    _tabTower = this->readFileCsv(path);
}

std::vector<std::vector<int>> FileReader::getFile()
{
    return _tabFile;
}

Ennemies* FileReader::getEnnemie(int id, Vect2 size)
{
    int i = 0;
    for (std::string col : _tabEnnemies[0])
    {
        if (col == "ID")
        {
            break;
        }

        i++;
    }

    int j = 0;
    for (std::vector<std::string> col : _tabEnnemies)
    {
        if (col[i] == to_string(id))
        {
            break;
        }

        j++;
    }

    int LifeMin = 0,
        LifeMax = 0,
        DamageMin = 0,
        DamageMax = 0,
        SpeedMin = 0,
        SpeedMax = 0,
        GoldMin = 0,
        GoldMax = 0,
        ColorFull = 0,
        ColorLow = 0;

    for (int i = 0; i < _tabEnnemies[0].size(); i++)
    {
        std::string testing = _tabEnnemies[0][i];
        if (testing == "Name") {
            cout << _tabEnnemies[j][i] << " ennemy was generated" << endl;
        }
        else if (testing == "LifeMin") {
            LifeMin = stoi(_tabEnnemies[j][i]);
        }
        else if (testing == "LifeMax") {
            LifeMax = stoi(_tabEnnemies[j][i]);
        }
        else if (testing == "DamageMin") {
            DamageMin = stoi(_tabEnnemies[j][i]);
        }
        else if (testing == "DamageMax") {
            DamageMax = stoi(_tabEnnemies[j][i]);
        }
        else if (testing == "SpeedMin") {
            SpeedMin = stoi(_tabEnnemies[j][i]);
        }
        else if (testing == "SpeedMax") {
            SpeedMax = stoi(_tabEnnemies[j][i]);
        }
        else if (testing == "GoldMin") {
            GoldMin = stoi(_tabEnnemies[j][i]);
        }
        else if (testing == "GoldMax") {
            GoldMax = stoi(_tabEnnemies[j][i]);
        }
        else if (testing == "ColorFull") {
            ColorFull = stringToHex(_tabEnnemies[j][i]);
        }
        else if (testing == "ColorLow") {
            ColorLow = stringToHex(_tabEnnemies[j][i]);
        }
    }

    Ennemies* newEnnemie = new Ennemies(size, 30, ColorFull, ColorLow, randint(SpeedMin, SpeedMax), randint(LifeMin, LifeMax), randint(DamageMin, DamageMax), randint(GoldMin, GoldMax));
    return newEnnemie;
}

Towers* FileReader::getTower(int id)
{
    int i = 0;
    for (std::string col : _tabTower[0])
    {
        if (col == "ID")
        {
            break;
        }

        i++;
    }

    int j = 0;
    for (std::vector<std::string> col : _tabTower)
    {
        if (col[i] == to_string(id))
        {
            break;
        }

        j++;
    }

    int Color = 0,
        ShootRate = 0,
        BulletSpeed = 0,
        Range = 0,
        BulletDamage = 0,
        Cost = 0;

    for (int i = 0; i < _tabTower[0].size(); i++)
    {
        std::string testing = _tabTower[0][i];
        if (testing == "Name") {
            cout << _tabTower[j][i] << " tower was generated" << endl;
        }
        else if (testing == "Color") {
            Color = stringToHex(_tabTower[j][i]);
        }
        else if (testing == "ShootRate") {
            ShootRate = stoi(_tabTower[j][i]);
        }
        else if (testing == "BulletSpeed") {
            BulletSpeed = stoi(_tabTower[j][i]);
        }
        else if (testing == "Range") {
            Range = stoi(_tabTower[j][i]);
        }
        else if (testing == "BulletDamage") {
            BulletDamage = stoi(_tabTower[j][i]);
        }
        else if (testing == "Cost") {
            Cost = stoi(_tabTower[j][i]);
        }
    }

    Towers* newTower = new Towers(Vect2(0, 0), Vect2(0, 0), Color, BulletDamage, ShootRate, Range, Cost, BulletSpeed);
    return newTower;
}

int FileReader::getFileHeight()
{
    return _sizeHeight;
}

int FileReader::randint(int a, int b)
{
    if (a > b)
    {
        int c = a;
        a = b;
        b = c;
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    return std::rand() % (b - a + 1) + a;
}

int FileReader::stringToHex(std::string str)
{
    int result = 0;
    for (int i = 2; i < str.size(); i++)
    {
        result *= 16;
        if (str[i] == '1')
        {
            result += 1;
        }
        else if (str[i] == '2')
        {
            result += 2;
        }
        else if (str[i] == '3')
        {
            result += 3;
        }
        else if (str[i] == '4')
        {
            result += 4;
        }
        else if (str[i] == '5')
        {
            result += 5;
        }
        else if (str[i] == '6')
        {
            result += 6;
        }
        else if (str[i] == '7')
        {
            result += 7;
        }
        else if (str[i] == '8')
        {
            result += 8;
        }
        else if (str[i] == '9')
        {
            result += 9;
        }
        else if (str[i] == 'a' || str[i] == 'A')
        {
            result += 10;
        }
        else if (str[i] == 'b' || str[i] == 'B')
        {
            result += 11;
        }
        else if (str[i] == 'c' || str[i] == 'C')
        {
            result += 12;
        }
        else if (str[i] == 'd' || str[i] == 'D')
        {
            result += 13;
        }
        else if (str[i] == 'e' || str[i] == 'E')
        {
            result += 14;
        }
        else if (str[i] == 'f' || str[i] == 'F')
        {
            result += 15;
        }
    }
    return result;
}
