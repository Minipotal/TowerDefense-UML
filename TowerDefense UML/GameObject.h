#pragma once

#include "Vect.h"

class GameObject
{
protected:
	float _color;
	int _speed;
	int _life;
	Vect2 _pos;
	Vect2 _size;

public:
	GameObject(Vect2 pos, Vect2 size, float color, int speed, int life);
	void minusHp(int number);
	void move(Vect2 direction);

	Vect2 pos();
	Vect2 size();

	bool isPointInside(const sf::Vector2i& mousePos);
	Shape* getShape();
};

