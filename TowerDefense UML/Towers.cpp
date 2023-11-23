#include "Towers.h"

#include "GameObject.h"
#include "Bullets.h"
#include "Ennemies.h"
#include "Math.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

Towers::Towers(Vect2 pos, Vect2 size, MyColor color, int damage, float cooldown, int range, int cost, int bulletSpeed) : GameObject(pos, size, color, 0, 0) {};
Towers::Towers() : Towers({ 0, 0 }, { 0, 0 }, 0x000000, 0, 0, 0, 0, 0) { };

int Towers::getCost()
{
    return _cost;
}

void Towers::levelUp(int damage)
{
	_damage += damage;
}

void Towers::ChooseTarget(std::vector<GameObject*> vEnnemiesList)
{
	//Choose Target
	GameObject* pTarget = NULL;
	for (int i = 0; i < vEnnemiesList.size(); i++)
	{
		if (Math::CircleToCircleColid(_pos, _range, vEnnemiesList[i]->pos(), vEnnemiesList[i]->size().x()) == true)
		{
			int iTargetX = 0;
			if (vEnnemiesList[i]->pos().x() > iTargetX)
			{
				iTargetX = vEnnemiesList[i]->pos().x();
				pTarget = vEnnemiesList[i];
				_pTarget = pTarget;
				_state = TowersStates::Targeting;
			}
		}
	}
	if (pTarget == NULL)
	{
		_pTarget = NULL;
		_state = TowersStates::Idle;
	}
}

void Towers::StateMachine()
{
	switch (_state)
	{
	case Idle:
		break;
	case Targeting:
		if (_oClock.getElapsedTime().asSeconds() >= 1)
		{
			float fBallDiametre = 20;
			Vect2 vBallPos = _pos;
			Bullets* oBullet = new Bullets(this, _pos, fBallDiametre, _damage, _color);
			_vBulletsList.push_back(oBullet);
			_oClock.restart();

		};
	default:
		break;
	}
}

//Ball Gestion
const std::vector<GameObject*>& Towers::GetBulletsList()
{
	return (_vBulletsList);
}
void Towers::RemoveFromBulletsList(Bullets* pBullets)
{
	_vBulletsList.erase(std::remove(_vBulletsList.begin(), _vBulletsList.end(), pBullets), _vBulletsList.end());
}