#pragma once
#include "GameObject.h"
class Base : public GameObject
{
public:
	Base(Vect2 pos, Vect2 size, float color, int speed, int life);

	int getHp();
};

