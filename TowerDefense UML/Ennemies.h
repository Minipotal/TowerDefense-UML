#pragma once

#include "Vect.h"
#include "GameObject.h"

class Ennemies : public GameObject
{
private:
	int _gold;
	int _state;
	int _name;
	int _damage;
	float _color, _deadColor;
	Vect2 _vDirection = Vect2(1, 0);

public:
	Ennemies(Vect2 pos, float size, float color, float deadColor, int speed, int life, int damage, int gold);
};

