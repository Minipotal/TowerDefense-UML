#include <iostream>
#include <thread>  

#include "FileReader.h"
#include "Window.h"

int main()
{
    FileReader* o_file = new FileReader();

    o_file->readFileTxt("Files/test.txt");

    MWindow* o_window = new MWindow(Vect2(1000, 800), "Tower Defence");

    std::this_thread::sleep_for(std::chrono::seconds(5));

}

