#include "Towers.h"
#include "GameObject.h"
#include "Bullets.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

Towers::Towers(Vect2 vPos, Vect2 vSize, sf::Color cColor) : GameObject(vPos, vSize, cColor)
{
	_cColor = cColor;
	_oClock.restart();
}




void Towers::ShootBullet()
{
	if (_oClock.getElapsedTime().asSeconds() >= 1)
	{
		float fBallDiametre = 20;
		Vect2 vBallPos = _vPos;
		Bullets* oBullet = new Bullets(this, _vPos, fBallDiametre, _iDamage, _cColor);
		_vBulletsList.push_back(oBullet);
		_oClock.restart();

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
void Towers::LevelUp()
{

}
