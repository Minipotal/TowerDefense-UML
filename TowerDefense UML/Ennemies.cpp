#include "Ennemies.h"


Ennemies::Ennemies(Vect2 pos, float rayon, float color, float deadColor, int speed, int life, int damage, int gold) : GameObject(pos, rayon, color, speed, life)
{
	_gold = gold;
	_color = color;
	_deadColor = deadColor;
	_damage = damage;
}
