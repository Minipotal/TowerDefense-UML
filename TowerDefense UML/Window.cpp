#include "Window.h"

#include "GameObject.h"

MWindow::MWindow(Vect2 size, std::string name)
{
	_size = size;
	_name = name;
	_window = new sf::RenderWindow(sf::VideoMode(_size.x(), _size.y()), _name);
}

void MWindow::display()
{

}

sf::RenderWindow* MWindow::getWindow()
{
	return _window;
}

void MWindow::winDraw(std::vector<GameObject*> o_gameObject)
{
	for (int i = 0; i < o_gameObject.size(); i++)
	{
		_window->draw(*o_gameObject[i]->getShape());
	}
}

void MWindow::winDraw(GameObject* gameObject)
{
		_window->draw(*gameObject->getShape());
}
