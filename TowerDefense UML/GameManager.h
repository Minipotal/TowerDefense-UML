#pragma once

#include <map>
#include <SFML/Graphics.hpp>
#include <vector>

class Towers;
class Ressources;
class Cases;
class Ennemies;
class MWindow;
class Base;
class GameObject;

class GameManager
{
private:
	static GameManager* _pInstance;
	GameManager() {};
	void Initialize();

	std::vector<Towers*> o_towers;
	std::vector<std::vector<Ennemies*>> o_ennemies;
	std::vector<std::vector<Cases*>> o_cases;

	MWindow* o_window;
	sf::RenderWindow* _window;
	Base* _base;

	Towers* _selectedTower;

	std::map<int, std::vector<GameObject*>> _entities;

public:

	Ressources* _ressource;
	sf::Vector2i* _mousePos;
	 
	typedef enum GameArea
	{
		None,
		Game,
	};

	typedef enum GameOLabel
	{
		Tower = 0,
		Case = 1,
		Ennemi = 2,
	};

	static void Create();

	static GameManager* Get()
	{
		return _pInstance;
	}

	void game();
	void initMobs();
	void initTowers();

	void Mbuy();
	void Mupgrade();
	void Mdestroy();

	void MTower1();
	void MTower2();
	void MTower3();
};

