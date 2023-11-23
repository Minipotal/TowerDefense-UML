#pragma once

#include "GameObject.h"

class Towers : public GameObject
{
private:
	int _damage;
	float _cooldown;
	int _range;
	int _cost;

public:
	Towers(Vect2 pos, Vect2 size, float color, int damage, float cooldown, int range, int cost);
	Towers();

	int getCost();
	void fire();
	void levelUp();
};