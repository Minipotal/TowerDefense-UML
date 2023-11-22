#pragma once

#include <map>

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
	std::vector<Ennemies*> o_popEnnemies;
	int _ennemiesSize;
	std::vector<Cases*> o_cases;

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
		Build,
		Upgrade,
		Destroy,
		Restart,
		Quit
	};

	static void Create();

	static GameManager* Get()
	{
		return _pInstance;
	}

	void Game();

	void initMobs();
	
	void Mquit();
	void Mbuy();
	void MbuttonClick();

	void Mupgrade();
	void Mdestroy();
};

