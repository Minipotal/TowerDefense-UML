#include "Cases.h"

#include "Towers.h"
#include "GameManager.h"
#include "Ressources.h"

Cases::Cases(Vect2 pos, Vect2 size, MyColor color, int speed, int life) : GameObject(pos, size, color, speed, life)
{
	_placedTower = new Towers();
	_isFilled = false;
}


void Cases::destroy(Ressources* o_ressources)
{
	if (!_isFilled) return;
	o_ressources->_gold += (int)(_placedTower->getCost() * .8f);
	_placedTower = new Towers();
	_isFilled = false;
}
void Cases::upgrade(Ressources* o_ressources)
{
	if (!_isFilled) return;
	if (o_ressources->_gold > _placedTower->getCost())
	{
		o_ressources->_gold -= _placedTower->getCost();
		_placedTower->levelUp(10);
		_isFilled = true;
	}
}
void Cases::buy(Towers* o_tower, Ressources* o_ressources)
{
	if (_isFilled) return;
	if (o_ressources->_gold > o_tower->getCost())
	{
		o_ressources->_gold -= o_tower->getCost();
		_placedTower = o_tower;
		sf::Shape* newShape = new sf::RectangleShape(Vect2(_size.x(), _size.y()).getVector2f());
		o_tower->SetShape(newShape);
		o_tower->SetPosition(Vect2(_pos.x(), _pos.y()));
		o_tower->SetSize(Vect2(_size.x(), _size.y()));
		_isFilled = true;
	}
}

bool Cases::isFilled()
{
	return _isFilled;
}

Towers* Cases::getTower()
{
	return _placedTower;
}


