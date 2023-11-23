#include "Base.h"

Base::Base(Vect2 pos, Vect2 size, MyColor color, int speed, int life) : GameObject(pos, size, color, speed, life) {};

int Base::getHp()
{
	return _life;
}
