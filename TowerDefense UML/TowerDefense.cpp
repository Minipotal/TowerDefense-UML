#include <iostream>
#include <thread>  

#include "FileReader.h"
#include "Window.h"
#include "GameManager.h"
#include "EventManager.h"

void Game()
{
	GameManager::Get()->game();
}

int main()
{
	EventManager::Create();
	GameManager::Create();
	Game();
}

