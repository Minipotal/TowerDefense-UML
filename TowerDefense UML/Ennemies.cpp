#include "Ennemies.h"
#include <ctime>
#include <cstdlib>


Ennemies::Ennemies(Vect2 pos, Vect2 size, float color, int speed, int life, int damage, int ID, int iLife, int iDamage, int iSpeed, int iGold) : GameObject(pos, size, color, speed, life)
{
	_life = randLife(minLife, maxLife);
	int damage = randDamage(minDamage, maxDamage);
	_speed = randSpeed(minSpeed, maxSpeed);
	int gold = randGold(minGold, maxGold);
}
