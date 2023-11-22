#pragma once
#include "GameObject.h"

class Towers;

class Cases : public GameObject
{
private:
	bool _isFilled;
	Towers* _placedTower;

public:
	Cases(Vect2 vPos, Vect2 vSize);

	void destroy();
	void upgrade();
	void buy(Towers* o_tower);
};

