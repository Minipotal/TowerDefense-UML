#pragma once

#include "GameObject.h"
#include "Towers.h"

class Bullets : public GameObject
{
private:
	int _damage;
	Towers* _tower;
	GameObject* _target;

public:
	Bullets(Towers* pTowers, Vect2 vPos, float iDiametre, int iDamage, float color);
};

