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


void Cases::destroy()
{
	if (!_isFilled) return;
	GameManager gm = GameManager();
	gm._ressources->_gold += _placedTower->GetCost() * .8f;
	_placedTower = new Towers(Vect2(20, 20), Vect2(30, 30), sf::Color(255, 0, 0));
	_isFilled = false;
}
void Cases::upgrade()
{
	if (!_isFilled) return;
	GameManager gm = GameManager();
	if (gm._ressources->_gold > _placedTower->GetCost())
	{
		gm._ressources->_gold -= _placedTower->GetCost();
		_placedTower->LevelUp();
		_isFilled = true;
	}
}
void Cases::buy(Towers* o_tower)
{
	if (_isFilled) return;
	GameManager gm = GameManager();
	if (gm._ressources->_gold > o_tower->GetCost())
	{
		gm._ressources->_gold -= o_tower->GetCost();
		_placedTower = o_tower;
		_isFilled = true;
	}
}

