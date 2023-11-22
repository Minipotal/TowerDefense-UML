#include "Ennemies.h"
#include <ctime>
#include <cstdlib>


Ennemies::Ennemies(Vect2 pos, Vect2 size, float color, int speed, int life, int damage, int ID, int minLife, int maxLife, int minDamage, int maxDamage, int minSpeed, int maxSpeed, int minGold, int maxGold) : GameObject(pos, size, color, speed, life)
{
	_life = randLife(minLife, maxLife);
	int damage = randDamage(minDamage, maxDamage);
	_speed = randSpeed(minSpeed, maxSpeed);
	int gold = randGold(minGold, maxGold);
}

int Ennemies::randSpeed(int minSpeed, int maxSpeed)
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	return std::rand() % (maxSpeed - minSpeed + 1) + minSpeed;
}

int Ennemies::randLife(int minLife, int maxLife)
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	return std::rand() % (maxGold - minGold + 1) + minGold;
}

int Ennemies::randGold(int minGold, int maxGold)
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	return std::rand() % (maxGold - minGold + 1) + minGold;
}

int Ennemies::randDamage(int minDamage, int maxDamage)
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	return std::rand() % (maxDamage - minDamage + 1) + minDamage;
}
