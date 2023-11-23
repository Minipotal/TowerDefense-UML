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

void upgrade()
{
	GameManager::Get()->Mupgrade();
}

void destroy()
{
	GameManager::Get()->Mdestroy();
}

void buy()
{
	GameManager::Get()->Mbuy();
}

void GameManager::Initialize()
{
	float windowWidth = 1920;
	float windowHeight = 1080;
	o_window = new MWindow(Vect2(windowWidth, windowHeight), "Tower Defense");
	_window = o_window->getWindow();
	_ressource = new Ressources();
	_mousePos = new sf::Vector2i();
	_base = new Base(Vect2(0, 0), Vect2(0, 0), 0xee33ff, 0, 10);

	float gameAreaWidth = windowWidth * 0.8;
	float gameAreaHeight = windowHeight * 1.0;

	float gameAreaStartX = 0;
	float gameAreaStartY = 0;
	
	int caseLineCount = 10;
	int caseColumnCount = 10;

	/* init entities */
	initMobs();

	// cases
	float startX = gameAreaStartX;
	float startY = gameAreaStartY;
	for (int i = 0; i < caseLineCount; i++)
	{
		for (int j = 0; j < caseColumnCount; j++)
		{
			o_cases[i].push_back(new Cases(Vect2(startX, startY), Vect2(gameAreaWidth / startX, gameAreaHeight / startY), 0x63340b, 0, 0));
			startX += gameAreaWidth / startX;
		}
		startX = gameAreaStartX;
		startY += gameAreaHeight / startY;
	}

	/* init events */
	EventManager::Get()->AddArea(Vect2(gameAreaStartX, gameAreaStartY), Vect2(gameAreaWidth, gameAreaHeight), GameArea::Game);
	EventManager::Get()->AddEvent(GameArea::Game, sf::Mouse::Button::Left, &buy);
	EventManager::Get()->AddEvent(GameArea::Game, sf::Mouse::Button::Middle, &upgrade);
	EventManager::Get()->AddEvent(GameArea::Game, sf::Mouse::Button::Right, &destroy);
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
	o_file->readFileTxt("Files/mobs.txt");

	for (int i = 0; i < o_file->getFile().size(); i++)
	{
		o_ennemies.resize(i);
		for (int j = 0; j < o_file->getFile()[i].size(); j++)
		{
			o_ennemies[i].resize(j);
			//o_ennemies[i][j].push_back(o_file->getFile()[i][j]); // id pour le moment, changer ave les bons params
		}
	}
}

void GameManager::initTowers()
{

}

void GameManager::Mbuy()
{
	for (int i = 0; i < o_cases.size(); i++)
	{
		for (int j = 0; j < o_cases[i].size(); j++)
		{
			if (o_cases[i][j]->isPointInside(*_mousePos))
			{
				//o_cases[i]->buy(, _ressource); // a modif qu'and y'aura les tours
				std::cout << "buy" << std::endl;
			}
		}
	}
}

void GameManager::Mupgrade()
{
	for (int i = 0; i < o_cases.size(); i++)
	{
		for (int j = 0; j < o_cases[i].size(); j++)
		{
			if (o_cases[i][j]->isPointInside(*_mousePos))
			{
				o_cases[i][j]->upgrade(_ressource);
			}
		}
	}
}

void GameManager::Mdestroy()
{
	for (int i = 0; i < o_cases.size(); i++)
	{
		for (int j = 0; j < o_cases[i].size(); j++)
		{
			if (o_cases[i][j]->isPointInside(*_mousePos))
			{
				o_cases[i][j]->destroy(_ressource);
			}
		}
	}
}

void GameManager::game()
{
	while (_window && _window->isOpen())
	{
		if (_base->getHp() == 0)
		{
			std::cout << "You loose" << std::endl;
		}
	}
}