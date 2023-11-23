#include "EventManager.h"

EventManager* EventManager::_pInstance = nullptr;

EventManager::EventManager()
{

}

void EventManager::CheckEvent(GameManager::GameArea area, sf::Mouse::Button eventName) {
	if (_dict.find(area) != _dict.end() && _dict[area].find(eventName) != _dict[area].end()) {
		_dict[area][eventName]();
	}
}

void EventManager::CheckEventKeyBoard(GameManager::GameArea area, sf::Keyboard::Key eventName) {
	if (_dictKeyboard.find(area) != _dictKeyboard.end() && _dictKeyboard[area].find(eventName) != _dictKeyboard[area].end()) {
		_dictKeyboard[area][eventName]();
	}
}

void EventManager::update(sf::RenderWindow* _window)
{
	sf::Event event;
	*GameManager::Get()->_mousePos = sf::Mouse::getPosition(*_window);

	while (_window->pollEvent(event))
	{
		if (event.type == sf::Event::EventType::Closed)
		{
			_window->close();
		}

		if (event.type == sf::Event::MouseButtonPressed)
		{
			for (int i = 0; i < m_oAreas.size(); i++)
			{
				if ((GameManager::Get()->_mousePos->x >= m_oAreas[i]._pos.x() && GameManager::Get()->_mousePos->x <= (m_oAreas[i]._size.x())) && (GameManager::Get()->_mousePos->y >= m_oAreas[i]._pos.y() && GameManager::Get()->_mousePos->y <= m_oAreas[i]._size.y()))
				{
					CheckEvent(m_oAreas[i]._eGameArea, event.mouseButton.button);
				}
			}
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			for (int i = 0; i < m_oAreasKeyboard.size(); i++)
			{
				CheckEventKeyBoard(m_oAreasKeyboard[i]._eGameArea, event.key.code);
			}
		}
	}
}	