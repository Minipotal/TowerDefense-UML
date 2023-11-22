//#include "Cases.h"
//
//#include "Towers.h"
//#include "GameManager.h"
//#include "Ressources.h"
//
//Cases::Cases(Vect2 pos, Vect2 size, float color, int speed, int life) : GameObject(pos, size, color, speed, life)
//{
//	_placedTower = new Towers();
//	_isFilled = false;
//}
//
//
//void Cases::destroy()
//{
//	if (!_isFilled) return;
//	GameManager gm = GameManager();
//	gm._ressources->_gold += _placedTower->getCost() * .8f;
//	_placedTower = new Towers();
//	_isFilled = false;
//}
//void Cases::upgrade()
//{
//	if (!_isFilled) return;
//	GameManager gm = GameManager();
//	if (gm._ressources->_gold > _placedTower->getCost())
//	{
//		gm._ressources->_gold -= _placedTower->getCost();
//		_placedTower->levelUp();
//		_isFilled = true;
//	}
//}
//void Cases::buy(Towers* o_tower)
//{
//	if (_isFilled) return;
//	GameManager gm = GameManager();
//	if (gm._ressources->_gold > o_tower->getCost())
//	{
//		gm._ressources->_gold -= o_tower->getCost();
//		_placedTower = o_tower;
//		_isFilled = true;
//	}
//}