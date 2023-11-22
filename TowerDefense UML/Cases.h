#pragma once
#include "GameObject.h"

class Towers;

class Cases : public GameObject
{
private:
	bool _isFilled;
	Towers* _placedTower;

public:
	Cases(Vect2 pos, Vect2 size, float color, int speed, int life);

	void destroy();
	void upgrade();
	void buy(Towers* o_tower);
};

