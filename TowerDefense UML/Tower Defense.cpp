#include <iostream>

#include "FileReader.h"
#include "Window.h"

int main()
{
    FileReader* o_file = new FileReader();

    o_file->readFileTxt("Files/test.txt");
    o_file->readFileCsv("Files/csv_for_ennemi.csv");

    //MWindow* o_window = new MWindow(Vect2(1000, 800), "Tower Defence");
}

