#include "Bullets.h"

Bullets::Bullets(Towers* pTower, Vect2 pos, float fDiametre, int iDamage, float color) : GameObject(pos, fDiametre, color, 1, 1)
{
	_tower = pTower;
	_damage = iDamage;
}