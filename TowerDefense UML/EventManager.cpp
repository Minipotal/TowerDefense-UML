#include "EventManager.h"

EventManager* EventManager::_pInstance = nullptr;

EventManager::EventManager()
{

}

void EventManager::CheckEvent(GameManager::GameArea area, sf::Event::EventType eventName) {
	if (_dict.find(area) != _dict.end() && _dict[area].find(eventName) != _dict[area].end()) {
		_dict[area][eventName]();
	}
}

void EventManager::update(sf::RenderWindow* _window)
{
	sf::Event event;
	*GameManager::Get()->_mousePos = sf::Mouse::getPosition(*_window);

	while (_window->pollEvent(event))
	{
		for (int i = 0; i < m_oAreas.size(); i++)
		{
			if ((GameManager::Get()->_mousePos->x >= m_oAreas[i]._pos.x() && GameManager::Get()->_mousePos->x <= (m_oAreas[i]._size.x())) && (GameManager::Get()->_mousePos->y >= m_oAreas[i]._pos.y() && GameManager::Get()->_mousePos->y <= m_oAreas[i]._size.y()))
			{
				if (event.key.code == sf::Keyboard::B)
				{
					m_oAreas[i]._eGameArea = GameManager::Get()->GameArea::Build;
				}
				else if (event.key.code == sf::Keyboard::U)
				{
					m_oAreas[i]._eGameArea = GameManager::Get()->GameArea::Upgrade;
				}
				else if (event.key.code == sf::Keyboard::D)
				{
					m_oAreas[i]._eGameArea = GameManager::Get()->GameArea::Destroy;
				}
				CheckEvent(m_oAreas[i]._eGameArea, event.type);
			}
			else {
				CheckEvent(GameManager::GameArea::Quit, event.type);
			}
		}
	}
}	