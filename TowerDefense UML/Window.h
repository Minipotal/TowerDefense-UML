#pragma once

#include "Vect.h"

#include <string>
#include <SFML/Graphics.hpp>

class MWindow
{
private:
	Vect2 _size;
	std::string _name;
	sf::RenderWindow* _window;

public:
	MWindow(Vect2 size, std::string _name);
	void display();

	sf::RenderWindow* getWindow();
};

