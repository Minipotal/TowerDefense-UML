#include "GameManager.h"

#include "EventManager.h"
#include "Towers.h"
#include "Ressources.h"
#include "Cases.h"
#include "Ennemies.h"
#include "Window.h"
#include "Base.h"
#include "FileReader.h"
#include "GameObject.h"

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

void tower1()
{
	GameManager::Get()->MTower1();
}

void tower2()
{
	GameManager::Get()->MTower2();
}

void tower3()
{
	GameManager::Get()->MTower3();
}

void GameManager::Initialize()
{
	float windowWidth = 1920;
	float windowHeight = 1080;

	float gameAreaWidth = windowWidth * 1.0;
	float gameAreaHeight = windowHeight * 1.0;

	float gameAreaStartX = 0;
	float gameAreaStartY = 0;

	int caseLineCount = 10;
	int caseColumnCount = 10;

	o_window = new MWindow(Vect2(windowWidth, windowHeight), "Tower Defense");
	_window = o_window->getWindow();
	_ressource = new Ressources(5000000,0, 0);
	_mousePos = new sf::Vector2i();
	_base = new Base(Vect2(1920 - 50, (windowHeight / 2) - (gameAreaHeight / caseColumnCount)), Vect2(50, (gameAreaHeight / caseColumnCount) * 2), 0x1CCFC9, 0, 100);
	_deltaTime = 0;
	_entities.resize(GameManager::GameOLabel::Total);
	_mobsArea = new GameObject(Vect2(0, (windowHeight/ 2) - (gameAreaHeight / caseColumnCount)), Vect2(windowWidth, (gameAreaHeight / caseColumnCount)*2), { 0x000000 }, 0, 0);
	_road = new GameObject(Vect2(0, (windowHeight / 2) - (gameAreaHeight / caseColumnCount) + (gameAreaHeight / caseColumnCount)/2), Vect2(windowWidth, (gameAreaHeight / caseColumnCount)), { 0x696969 }, 0, 0);
	o_cases.resize(caseLineCount);
	
	/* init entities */
	initMobs();
	initTowers();

	_selectedTower = o_towers[0];

	// cases
	float startX = gameAreaStartX;
	float startY = gameAreaStartY;
	for (int i = 0; i < caseLineCount; i++)
	{
		for (int j = 0; j < caseColumnCount; j++)
		{
			o_cases[i].push_back(new Cases(Vect2(startX, startY), Vect2(gameAreaWidth / caseLineCount, gameAreaHeight / caseColumnCount), { 0x63340b }, 0, 0));
			_entities[GameManager::GameOLabel::Case].push_back(o_cases[i][j]);
			startX += gameAreaWidth / caseLineCount;
		}
		startX = gameAreaStartX;
		startY += gameAreaHeight / caseColumnCount;
	}

	/* init events */
	EventManager::Get()->AddAreaKeyBoard(Vect2(0,0), Vect2(0,0), GameArea::Game);
	EventManager::Get()->AddArea(Vect2(gameAreaStartX, gameAreaStartY), Vect2(gameAreaWidth, gameAreaHeight), GameArea::Game);

	EventManager::Get()->AddEvent(GameArea::Game, sf::Mouse::Button::Left, &buy);
	EventManager::Get()->AddEvent(GameArea::Game, sf::Mouse::Button::Middle, &upgrade);
	EventManager::Get()->AddEvent(GameArea::Game, sf::Mouse::Button::Right, &destroy);

	EventManager::Get()->AddEventKeyBoard(GameArea::Game, sf::Keyboard::Key::Num1, &tower1);
	EventManager::Get()->AddEventKeyBoard(GameArea::Game, sf::Keyboard::Key::Num2, &tower2);
	EventManager::Get()->AddEventKeyBoard(GameArea::Game, sf::Keyboard::Key::Num3, &tower3);
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
	o_file->readFileEnnemie("Files/csv_for_ennemi.csv");

	int startX = 0;
	int startY = 1080 / 2;

	o_ennemies.resize(o_file->getFile().size());

	for (int i = 0; i < o_file->getFile().size(); i++)
	{
		for (int j = 0; j < o_file->getFile()[i].size(); j++)
		{
			o_ennemies[i].resize(j);
			o_ennemies[i].push_back(o_file->getEnnemie(o_file->getFile()[i][j], Vect2(startX, startY - 30)));
			_entities[GameManager::GameOLabel::Ennemi].push_back(o_ennemies[i][j]);
			startX -= 200;
		}
		startX -= 500;
	}
}

void GameManager::initTowers()
{
	FileReader* o_file = new FileReader();
	o_file->readFileTower("Files/csv_for_tower.csv");

	int max = 3;
	for (int id = 0; id < max; id++)
	{
		o_towers.push_back(o_file->getTower(id));
	}
}

void GameManager::Mbuy()
{
	if (_selectedTower == nullptr)
		return;
	for (int i = 0; i < o_cases.size(); i++)
	{
		for (int j = 0; j < o_cases[i].size(); j++)
		{
			if (o_cases[i][j]->isPointInside(*_mousePos))
			{
				if (!o_cases[i][j]->isFilled())
				{
					o_cases[i][j]->buy(_selectedTower, _ressource);
					_entities[GameManager::GameOLabel::Tower].push_back(_selectedTower);
				}
			}
		}
	}
}

void GameManager::Mupgrade()
{
	if (_selectedTower == nullptr)
		return;
	for (int i = 0; i < o_cases.size(); i++)
	{
		for (int j = 0; j < o_cases[i].size(); j++)
		{
			if (o_cases[i][j]->isFilled())
			{
				if (o_cases[i][j]->isPointInside(*_mousePos))
				{
					o_cases[i][j]->upgrade(_ressource);
				}
			}
		}
	}
}

void GameManager::Mdestroy()
{
	if (_selectedTower == nullptr)
		return;
	for (int i = 0; i < o_cases.size(); i++)
	{
		for (int j = 0; j < o_cases[i].size(); j++)
		{
			if (o_cases[i][j]->isPointInside(*_mousePos))
			{
				if (o_cases[i][j]->isFilled())
				{
					_entities[GameManager::GameOLabel::Tower].erase(std::remove(_entities[GameManager::GameOLabel::Tower].begin(), _entities[GameManager::GameOLabel::Tower].end(), o_cases[i][j]->getTower()), _entities[GameManager::GameOLabel::Tower].end());
					o_cases[i][j]->destroy(_ressource);
				}
			}
		}
	}
}

void GameManager::MTower1()
{
	_selectedTower = o_towers[0];
}

void GameManager::MTower2()
{
	_selectedTower = o_towers[1];
}

void GameManager::MTower3()
{
	_selectedTower = o_towers[2];
}

void GameManager::game()
{
	while (_window && _window->isOpen())
	{
		sf::Clock oClock;

		EventManager::Get()->update(_window);
		_ressource->setIron(1);
		_ressource->setWood(2);

		if (_base->getHp() <= 0)
		{
			std::cout << std::endl << "You loose" << std::endl;
			return;
		}

		std::cout << _entities[GameManager::GameOLabel::Ennemi].size() << std::endl;
		if (_entities[GameManager::GameOLabel::Ennemi].size() == 0)
		{
			std::cout << std::endl << "You Win" << std::endl;
			return;
		}

		for (int i = 0; i < _entities[GameManager::GameOLabel::Tower].size(); i++)
		{
			_entities[GameManager::GameOLabel::Tower][i]->ChooseTarget(_entities[1]);
			_entities[GameManager::GameOLabel::Tower][i]->StateMachine();

			for (int j = 0; j < _entities[GameManager::GameOLabel::Tower][i]->GetBulletsList().size(); j++)
			{
				_entities[GameManager::GameOLabel::Tower][i]->GetBulletsList()[j]->Movement(_deltaTime);
				_entities[GameManager::GameOLabel::Tower][i]->GetBulletsList()[j]->EnnemiesColid(_entities[GameManager::GameOLabel::Ennemi]);


			}
		}

		for (int i = 0; i < _entities[GameManager::GameOLabel::Ennemi].size(); i++)
		{
			_entities[GameManager::GameOLabel::Ennemi][i]->move(Vect2(1, 0), _entities[GameManager::GameOLabel::Ennemi][i]->GetSpeed(),_deltaTime);
			if (_entities[GameManager::GameOLabel::Ennemi][i]->GetLife() <= 0)
			{
				_entities[GameManager::GameOLabel::Ennemi].erase(std::remove(_entities[GameManager::GameOLabel::Ennemi].begin(), _entities[GameManager::GameOLabel::Ennemi].end(), _entities[GameManager::GameOLabel::Ennemi][i]), _entities[GameManager::GameOLabel::Ennemi].end());
			}
			else if (_base->collideEnemie(_entities[GameManager::GameOLabel::Ennemi][i]))
			{
				_base->minusHp(_entities[GameManager::GameOLabel::Ennemi][i]->getDamage());
				_entities[GameManager::GameOLabel::Ennemi].erase(std::remove(_entities[GameManager::GameOLabel::Ennemi].begin(), _entities[GameManager::GameOLabel::Ennemi].end(), _entities[GameManager::GameOLabel::Ennemi][i]), _entities[GameManager::GameOLabel::Ennemi].end()); // destroy ennemi
			}
		}

		// draw
		_window->clear();

		
		for (int i = 0; i < _entities.size(); i++)
		{
			if (i == GameOLabel::Ennemi)
			{
				o_window->winDraw(_mobsArea);
				o_window->winDraw(_road);
				o_window->winDraw(_base);

			}
			o_window->winDraw(_entities[i]);

		}
		for (int j = 0; j < _entities[GameOLabel::Tower].size(); j++)
		{
			o_window->winDraw(_entities[GameOLabel::Tower][j]->GetBulletsList());
		}

		_window->display();

		_deltaTime = oClock.restart().asSeconds();
	}
}





void GameManager::HoverCase()
{
	sf::Vector2i _mousePos = sf::Mouse::getPosition(*_window);
	for (int i = 0; i < o_cases.size(); i++)
	{
		for (int j = 0; j < o_cases[i].size(); j++)
		{
			if ((o_cases[i][j]->pos().x() < _mousePos.x) && (_mousePos.x < o_cases[i][j]->pos().x() + o_cases[i][j]->size().x()) && (o_cases[i][j]->pos().y() < _mousePos.y) && (_mousePos.y < o_cases[i][j]->pos().y() + o_cases[i][j]->size().y()))
			{
				o_cases[i][j]->SetBorderColor(sf::Color(55, 55, 55));
			}
			else
			{
				o_cases[i][j]->SetBorderColor(sf::Color::Black);
			}
		}
	}
}