#pragma once

#include "GameObject.h"

class Bullets : public GameObject
{
private:
	int _damage;

public:
	Bullets(Vect2 pos, Vect2 size, float color, int speed, int life, int damage);
};

