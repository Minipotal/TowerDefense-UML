#pragma once
#include "GameObject.h"

class Towers;

class Bullets : public GameObject
{
private:
	Towers* _pTower;
	int _iDamage;
	GameObject* _pTarget;

public:
	Bullets(Towers* pTowers, Vect2 vPos, float iDiametre, int iDamage, sf::Color cColor);
	void Movement(float fDeltaTime, sf::RenderWindow* pWindow);

	
};
