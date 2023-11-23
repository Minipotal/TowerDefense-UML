#include "Cases.h"
#include "Towers.h"
#include "GameManager.h"
#include "Ressources.h"
#include<SFML/Graphics/Color.hpp>

Cases::Cases(Vect2 vPos, Vect2 vSize) : GameObject(vPos, vSize, sf::Color::Red)
{
	_placedTower = new Towers(vPos, vSize, sf::Color(255, 0, 0));
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
		_placedTower->levelUp();
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
		_isFilled = true;
	}
}

Towers* Cases::getTower()
{
	return _placedTower;
}

