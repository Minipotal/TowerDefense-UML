#pragma once
#include "GameObject.h"

class Towers;
class Ressources;

class Cases : public GameObject
{
private:
	bool _isFilled;
	Towers* _placedTower;

public:
	Cases(Vect2 pos, Vect2 size, MyColor color, int speed, int life);

	void destroy(Ressources* o_ressources);
	void upgrade(Ressources* o_ressources);
	void buy(Towers* o_tower, Ressources* o_ressources);

	Towers* getTower();
};