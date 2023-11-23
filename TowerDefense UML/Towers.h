#pragma once

#include "GameObject.h"

class Towers : public GameObject
{
private:
	int damage;
	float cooldown;
	int range;
	int cost;
	int bulletSpeed;

public:
	Towers(Vect2 pos, Vect2 size, float color, int damage, float cooldown, int range, int cost, int bulletSpeed);
	Towers();

	int getCost();
	void fire();
	void levelUp();
};