#include "Ennemies.h"

#include <ctime>
#include <cstdlib>
#include<SFML/Graphics/Color.hpp>

Ennemies::Ennemies(float fDiameter, sf::Color cColor, sf::Color cDeadColor, int iSpeed, int iLife, int iDamage, int iGold) : GameObject(Vect2(20,20), fDiameter, cDeadColor)
{
	_iSpeed = iSpeed;
	_iDamage = iDamage;
	_iGold = iGold;
	_iLife = iLife;
}
