#pragma once

#include "GameManager.h"

#include <SFML/Graphics.hpp>

#include "Vect.h"


class Cases;
typedef void (*event)();


struct Area
{
	Vect2 _pos;
	Vect2 _size;
	GameManager::GameArea _eGameArea;
	Area(Vect2 pos, Vect2 size, GameManager::GameArea eGameArea)
	{
		_pos = pos;
		_size = size;
		_eGameArea = eGameArea;
	}
};

class EventManager
{
private:
	static EventManager* _pInstance;
	EventManager();

public:
	std::vector<Area> m_oAreas;
	std::vector<Area> m_oAreasKeyboard;
	std::map<int, std::map<sf::Mouse::Button, event>> _dict;
	std::map<int, std::map<sf::Keyboard::Key, event>> _dictKeyboard;

	static void Create()
	{
		if (_pInstance != nullptr)
			return;

		_pInstance = new EventManager();
	}

	static EventManager* Get()
	{
		return _pInstance;
	}

	void AddEvent(GameManager::GameArea area, sf::Mouse::Button eEventType, event oFunction)
	{
		_dict[area][eEventType] = oFunction;
	}

	void AddEventKeyBoard(GameManager::GameArea area, sf::Keyboard::Key eEventType, event oFunction)
	{
		_dictKeyboard[area][eEventType] = oFunction;
	}

	void AddArea(Vect2 pos, Vect2 size, GameManager::GameArea eGameArea)
	{
		m_oAreas.push_back(Area(pos, size, eGameArea));
	}

	void AddAreaKeyBoard(Vect2 pos, Vect2 size, GameManager::GameArea eGameArea)
	{
		m_oAreasKeyboard.push_back(Area(pos, size, eGameArea));
	}

	void CheckEvent(GameManager::GameArea area, sf::Mouse::Button eventName);
	void CheckEventKeyBoard(GameManager::GameArea area, sf::Keyboard::Key eventName);

	void update(sf::RenderWindow* _window);
};

