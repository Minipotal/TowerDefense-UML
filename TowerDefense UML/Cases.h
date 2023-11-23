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
	Cases(Vect2 vPos, Vect2 vSize);

	void destroy(Ressources* o_ressources);
	void upgrade(Ressources* o_ressources);
	void buy(Towers* o_tower, Ressources* o_ressources);

	Towers* getTower();
};