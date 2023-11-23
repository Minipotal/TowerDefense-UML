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

public:

	Ressources* _ressource;
	sf::Vector2i* _mousePos;
	 
	typedef enum GameArea
	{
		None,
		Game,
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
};

