#include "Base.h"

#include "Ennemies.h"

Base::Base(Vect2 pos, Vect2 size, MyColor color, int speed, int life) : GameObject(pos, size, color, speed, life) {};

int Base::getHp()
{
	return _life;
}

bool Base::collideEnemie(GameObject* ennemies)
{
	if (ennemies->pos().x() >= _pos.x() && ennemies->pos().y() <= _pos.y() + _size.y() && ennemies->pos().y() >= _pos.y())
	{
		return true;
	}
	return false;
}