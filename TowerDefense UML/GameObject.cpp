#include "GameObject.h"

GameObject::GameObject(Vect2 pos, Vect2 size, MyColor color, int speed, int life) //rectangle
{
	_pos = pos;
	_size = size;
	_color = color;
	_speed = speed;
	_life = life;

	_shape = new sf::RectangleShape(_size.getVector2f());
	_shape->setPosition(_pos.getVector2f());
	_shape->setFillColor(_color.getSfColor());
	_shape->setOutlineThickness(3);
	_shape->setOutlineColor(sf::Color::Black);
}

GameObject::GameObject(Vect2 pos, float rayon, MyColor color, int speed, int life) //circle
{
	_pos = pos;
	_size = (rayon*2, rayon*2);
	_color = color;
	_speed = speed;
	_life = life;

	_shape = new sf::CircleShape(rayon);
	_shape->setPosition(_pos.getVector2f());
	_shape->setFillColor(_color.getSfColor());
}

void GameObject::minusHp(int number)
{
	_life -= number;
}

void GameObject::move(Vect2 direction)
{
	_pos += direction * _speed;
}

Vect2 GameObject::pos()
{
	return _pos;
}

Vect2 GameObject::size()
{
	return _size;
}


void GameObject::SetPosition(Vect2 vPos)
{
	_pos = vPos;
	_shape->setPosition(vPos.getVector2f());
}

void GameObject::SetSize(Vect2 size)
{
	_size = size;
}

void GameObject::SetOrigin(Vect2 vPos)
{
	_shape->setOrigin(vPos.getVector2f());
}
void GameObject::SetBorderColor(sf::Color cColor)
{
	_shape->setOutlineColor(cColor);
}
void GameObject::SetShape(sf::Shape* newShape)
{
	_shape = newShape;
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
	return _shape;
}

sf::Color GameObject::getColor()
{
	return _color.getSfColor();
}

void GameObject::ChooseTarget(std::vector<GameObject*> vEnnemiesList)
{
}

const std::vector<GameObject*>& GameObject::GetBulletsList()
{
	std::vector<GameObject*> o_objects;
	o_objects.resize(1);
	o_objects.push_back(new GameObject(Vect2(0, 0), Vect2(0, 0), 0, 0, 0));
	return o_objects;
}

void GameObject::Movement(float deltaTime)
{
}

