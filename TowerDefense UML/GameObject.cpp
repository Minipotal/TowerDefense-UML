#include "GameObject.h"

GameObject::GameObject(Vect2 pos, Vect2 size, float color, int speed, int life)
{
	_pos = pos;
	_size = size;
	_color = color;
	_speed = speed;
	_life = life;
}

void GameObject::minusHp(int number)
{
	_life -= number;
}

void GameObject::move(Vect2 direction)
{
	_pos += direction;
}