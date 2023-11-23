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

void MWindow::winDraw(GameObject* o_gameObject)
{
	_window->draw(*o_gameObject->getShape());
}
