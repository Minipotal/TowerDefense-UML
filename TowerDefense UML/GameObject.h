#pragma once

#include "Vect.h"

class GameObject
{
protected:
	Vect2 _pos;
	Vect2 _size;
	float _color;
	int _speed;
	int _life;

public:
	GameObject(Vect2 pos, Vect2 size, float color, int speed, int life);
	void minusHp(int number);
	void move(Vect2 direction);
};

