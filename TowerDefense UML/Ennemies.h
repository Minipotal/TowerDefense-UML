#pragma once

#include "GameObject.h"

typedef enum EnemiesStates
{
	Movement
};

class Ennemies : public GameObject
{
private :
	int _ID, _iDamage, _iGold;
public:
	Ennemies(Vect2 vPos, float fDiameter, int iLife);


};

