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

Vect2 GameObject::pos()
{
	return _pos;
}

Vect2 GameObject::size()
{
	return _size;
}


bool GameObject::isPointInside(const sf::Vector2i& mousePos)
{
	if (mousePos.x < _pos.x() || mousePos.x > _pos.x() + _size.x())
		return false;
	if (mousePos.y < _pos.y() || mousePos.y > _pos.y() + _size.y())
		return false;
	return true;
}

Shape* GameObject::getShape()
{
	return nullptr; // a modif
}

