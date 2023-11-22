#include "GameManager.h"

#include "EventManager.h"
#include "Towers.h"
#include "Ressources.h"
#include "Cases.h"
#include "Ennemies.h"
#include "Window.h"
#include "Base.h"
#include "FileReader.h"

GameManager* GameManager::_pInstance = nullptr;

void quit() 
{
	GameManager::Get()->Mquit();
}

void MbuttonClick()
{
	GameManager::Get()->MbuttonClick();
}

void upgrade()
{
	GameManager::Get()->Mupgrade();
}

void destroy()
{
	GameManager::Get()->Mdestroy();
}

void GameManager::Initialize()
{
	o_window = new MWindow(Vect2(1000, 800), "Tower Defense");
	_window = o_window->getWindow();
	_ressource = new Ressources();
	_mousePos = new sf::Vector2i();
	_base = new Base(Vect2(0, 0), Vect2(0, 0), 0xee33ff, 0, 10);

	// Event
	for (int i = 0; i < o_cases.size(); i++)
	{
		EventManager::Get()->AddArea(o_cases[i]->pos(), o_cases[i]->size(), GameArea::Game);
	}

	EventManager::Get()->AddEvent(GameArea::Upgrade, sf::Event::EventType::MouseButtonPressed, &upgrade);
	EventManager::Get()->AddEvent(GameArea::Destroy, sf::Event::EventType::MouseButtonPressed, &destroy);

	EventManager::Get()->AddEvent(GameArea::Quit, sf::Event::EventType::Closed, &quit);
}

void GameManager::Create()
{
	if (GameManager::_pInstance != nullptr)
		return;

	GameManager::_pInstance = new GameManager();
	GameManager::_pInstance->Initialize();
}

void GameManager::initMobs()
{
	FileReader* o_file = new FileReader();
	o_file->readFileTxt("Files/test.txt");

	for (int i = 0; i < o_file->getFile().size(); i++)
	{
		o_ennemies.resize(i);
		for (int j = 0; j < o_file->getFile()[i].size(); j++)
		{
			o_ennemies[i].resize(j);
			o_ennemies[i][j].push_back(o_file->getFile()[i][j]);
		}
	}
}

void GameManager::Mquit()
{
	_window->close();
}

void GameManager::Mbuy()
{

}

void GameManager::MbuttonClick()
{

}

void GameManager::Mupgrade()
{

}


void GameManager::Mdestroy()
{
}

void GameManager::Game()
{
	while (_window && _window->isOpen())
	{
		if (_base->getHp() == 0)
		{
			std::cout << "You loose" << std::endl;
		}
	}
}