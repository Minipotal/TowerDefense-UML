#pragma once

#include "GameObject.h"

class Ennemies : public GameObject
{
private :
	int _iID, _iDamage, _iGold;
	int _iState;
	sf::Color cColor, cDeadColor;
	Vect2 _vDirection = Vect2(1,0);
  
public:
	Ennemies(float fDiameter, sf::Color cColor, sf::Color cDeadColor, int iSpeed, int iLife, int iDamage, int iGold);
};

