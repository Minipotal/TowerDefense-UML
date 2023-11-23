#pragma once

#include "GameObject.h"

class Ennemies : public GameObject
{
private :
	int ID, minLife, maxLife, 
		minDamage, maxDamage, minSpeed, 
		maxSpeed, minGold, maxGold;
public:
	Ennemies(Vect2 pos, Vect2 size, float color, int speed, int life, int damage, int ID, int iLife, int iDamage, int iSpeed, int iGold);

};

