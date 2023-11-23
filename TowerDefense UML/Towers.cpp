#include "Towers.h"
#include "GameObject.h"
#include "Bullets.h"
#include "Ennemies.h"
#include "Math.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

Towers::Towers(Vect2 vPos, Vect2 vSize, sf::Color cColor) : GameObject(vPos, vSize, cColor)
{
	_cColor = cColor;
	_oClock.restart();
}

void Towers::ChooseTarget(std::vector<Ennemies*> vEnnemiesList)
{
	//Choose Target
	Ennemies* pTarget = NULL;
	for (int i = 0; i < vEnnemiesList.size(); i++)
	{
		if (Math::CircleToCircleColid(_vPos,_iRange, vEnnemiesList[i]->GetPosition(), vEnnemiesList[i]->GetSize().x()) == true)
		{
			int iTargetX = 0;
			if (vEnnemiesList[i]->GetPosition().x() > iTargetX)
			{
				iTargetX = vEnnemiesList[i]->GetPosition().x();
				pTarget = vEnnemiesList[i];
				_pTarget = pTarget;
				_iState = TowersStates::Targeting;
			}
		}
	}
	if (pTarget == NULL)
	{
		_pTarget = NULL;
		_iState = TowersStates::Idle;
	}
}

void Towers::StateMachine()
{
	switch (_iState)
	{
	case Idle:
		break;
	case Targeting:
		if (_oClock.getElapsedTime().asSeconds() >= 1)
		{
			float fBallDiametre = 20;
			Vect2 vBallPos = _vPos;
			Bullets* oBullet = new Bullets(this, _vPos, fBallDiametre, _iDamage, _cColor);
			_vBulletsList.push_back(oBullet);
			_oClock.restart();

		};
	default:
		break;
	}
}

//Ball Gestion
const std::vector<Bullets*>& Towers::GetBulletsList() const
{
	return (_vBulletsList);
}
void Towers::RemoveFromBulletsList(Bullets* pBullets)
{
	_vBulletsList.erase(std::remove(_vBulletsList.begin(), _vBulletsList.end(), pBullets), _vBulletsList.end());
}

/////////////Temporaire
int Towers::GetCost()
{
	return 0;
}
