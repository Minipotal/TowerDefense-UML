#pragma once

#include "GameObject.h"

class Ennemies : public GameObject
{
private :
	int ID, minLife, maxLife, 
		minDamage, maxDamage, minSpeed, 
		maxSpeed, minGold, maxGold;
public:
	Ennemies(Vect2 pos, Vect2 size, float color, int speed, int life, int damage, int ID, int minLife, int maxLife, int minDamage, int maxDamage, int minSpeed, int maxSpeed, int minGold, int maxGold);

	int randSpeed(int minSpeed, int maxSpeed);
	int randLife(int minLife, int maxLife);
	int randGold(int minGold, int maxGold);
	int randDamage(int minDamage, int maxDamage);

};

